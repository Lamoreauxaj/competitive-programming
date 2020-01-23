#ifndef CPLIB_CPP
#define CPLIB_CPP
#include <bits/stdc++.h>
using namespace std;

void solve();

using ll = long long;
using ld = long double;
#define x first
#define y second
int MOD = 1000000007;
ll INF = 100000000000000000;
ld EPS = 1e-9;
ld PI = acos(-1);

void solve_wrapper() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(10);
    solve();
}

string write_file(string str);
void testfile(string input_file, string output_file, int timeout=1000);
void testcase(string input, string output, int timeout=1000);
void testcli();
bool diff(string file1, string fil2, string& data1, string& data2);
int execute(int test_num);
int run_tests();
int test();
int test(int test_num);
template <typename T, typename... Types>
int test(T test_num, Types... args);
string is_include(string line);
void cplib(string main);
void input_file(string file);
void output_file(string file);

#ifndef LOCAL
void testfile(string input_file, string output_file, int timeout) {}
void testcase(string input, string output, int timeout) {}
void testcli() {}
int test() {
    solve_wrapper();
    return 0;
}
int test(int test_num) {
    solve_wrapper();
    return 0;
}
template <typename T, typename... Types>
int test(T test_num, Types... args) {
    solve_wrapper();
    return 0;
}
void cplib(string main) {}
void input_file(string file) { freopen(file.c_str(), "r", stdin); }
void output_file(string file) { freopen(file.c_str(), "w", stdout); }
#else
#include <sys/wait.h>
#include <unistd.h>
vector<string> inputs, outputs;
vector<bool> manual;
vector<int> timeouts;
vector<string> tmp_files;

string write_file(string str) {
    char tmp[] = "/tmp/cplib.XXXXXX";
    int f = mkstemp(tmp);
    write(f, str.c_str(), str.size());
    close(f);
    tmp_files.push_back(string(tmp));
    return tmp;
}

void testfile(string input_file, string output_file, int timeout) {
    inputs.push_back(input_file);
    outputs.push_back(output_file);
    timeouts.push_back(timeout);
    manual.push_back(false);
}

void testcase(string input, string output, int timeout) {
    testfile(write_file(input), write_file(output), timeout);
}

void testcli() {
    testfile("cli", "cli", 10000000);
    manual[manual.size() - 1] = true;
}

bool diff(string file1, string file2, string& data1, string& data2) {
    ifstream f1(file1);
    ifstream f2(file2);
    stringstream ss1; ss1 << f1.rdbuf();
    stringstream ss2; ss2 << f2.rdbuf();
    data1 = ss1.str();
    data2 = ss2.str();
    if (data1[data1.size() - 1] != '\n') data1 += '\n';
    if (data2[data2.size() - 1] != '\n') data2 += '\n';

    bool match = data1 == data2;

    int CAP = 30;

    stringstream ss(data1);
    string line;
    data1 = "";
    int printed = 0;
    while (printed++ < CAP && getline(ss, line))
        data1 += line + "\n";
    if (getline(ss, line))
        data1 += "...\n";
    ss = stringstream(data2);
    data2 = "";
    printed = 0;
    while (printed++ < CAP && getline(ss, line))
        data2 += line + "\n";
    if (getline(ss, line))
        data2 += "...\n";

    return match;
}

int punt;
void sig_handler(int sig) {
    punt = 1;
}

int execute(int test_num) {
    string tmp_output = write_file("");
    cout << "Test: " << test_num << endl;
    int pid = fork();
    if (!pid) {
        if (!manual[test_num - 1]) {
            freopen(inputs[test_num - 1].c_str(), "r", stdin);
            freopen(tmp_output.c_str(), "w", stdout);
        }
        solve_wrapper();
        exit(0);
    }
    else {
        struct timeval timeout = {0, timeouts[test_num - 1] * 1000};

        int rc;
        signal(SIGCHLD, sig_handler);
        rc = select(0, NULL, NULL, NULL, &timeout);

        string program_output, correct_output;
        int ret_value = 0;
        string res = "UN";
        if (rc == 0) {
            res = "TLE";
        }
        else if (punt) {
            int status;
            wait(&status);
            ret_value = WEXITSTATUS(status);

            bool match = diff(outputs[test_num - 1], tmp_output, correct_output, program_output);
            if (ret_value != 0) {
                res = "RTE";
            }
            else {
                if (match) {
                    res = "AC";
                }
                else {
                    res = "WA";
                }
            }
        }

        cout << "Result: " << res << endl;
        if (res == "RTE")
            cout << "Return Value: " << ret_value << endl;
        if (res == "WA" || res == "RTE" || res == "TLE")
            cout << "Correct Output: " << outputs[test_num - 1] << "\n" << correct_output,
            cout << "Program Output: " << tmp_output << "\n" << program_output << flush;
    }
}

bool first_test = true;
vector<int> test_nums;

int run_tests() {
    int res = 0;
    for (int i : test_nums)
        res |= execute(i);
    for (string s : tmp_files)
        remove(s.c_str());
    return res;
}

int test() {
    for (int i = 1; i <= inputs.size(); i++)
        test_nums.push_back(i);
    return run_tests();
}

int test(int test_num) {
    if (test_num <= 0 || test_num > inputs.size()) {
        cerr << "Invalid test number\n";
        exit(1);
    }
    bool first = first_test;
    if (first) test_nums.clear();
    test_nums.push_back(test_num);
    if (first) {
        return run_tests();
    }
    return 0;
}

template <typename T, typename... Types>
int test(T test_num, Types... args) {
    if (test_num <= 0 || test_num > inputs.size()) {
        cerr << "Invalid test number\n";
        exit(1);
    }
    bool first = first_test;
    first_test = false;
    if (first) test_nums.clear();
    test_nums.push_back(test_num);
    test(args...);
    if (first) {
        return run_tests();
    }
    return 0;
}

string is_include(string line) {
    int i = 0;
    while (i < line.size() && line[i] == ' ') i++;
    if (i + 7 >= line.size()) return "";
    if (line.substr(i, 8) != "#include") return "";
    i += 8;
    while (i < line.size() && line[i] == ' ') i++;
    if (line[i] != '\"') return "";
    i++;
    int j = i + 1;
    while (j < line.size() && line[j] != '\"') j++;
    if (j == line.size()) return "";
    int k = j + 1;
    while (k < line.size() && line[k] == ' ') k++;
    if (k != line.size()) return "";
    return line.substr(i, j - i);
}

void cplib(string main) {
    #ifndef COMPILE
    return;
    #endif
    string INC_PATH = getenv("CPLUS_INCLUDE_PATH");
    vector<string> inc_paths;
    inc_paths.push_back("./");
    int cnt = 0;
    for (int i = 0; i <= INC_PATH.size(); i++) {
        if (i == INC_PATH.size() || INC_PATH[i] == ':') {
            if (cnt > 0) {
                string path = INC_PATH.substr(i - cnt, cnt);
                if (path[path.size() - 1] != '/')
                    path += "/";
                inc_paths.push_back(path);
            }
            cnt = 0;
        }
        else cnt++;
    }

    unordered_set<string> visit;
    queue<string> q;
    q.push("./" + main);
    vector<string> lines;
    while (!q.empty()) {
        string p = q.front(); q.pop();
        if (visit.count(p)) continue;
        visit.insert(p);
        ifstream f(p);
        stringstream ss; ss << f.rdbuf();
        string line;
        vector<string> tmp_lines;
        while (getline(ss, line))
            tmp_lines.push_back(line);
        for (int i = tmp_lines.size() - 1; i >= 0; i--) {
            line = tmp_lines[i];
            string inc = is_include(line);
            if (inc != "") {
                for (string inc_path : inc_paths) {
                    string path = inc_path + inc;
                    ifstream fp(path);
                    if (fp) {
                        q.push(path);
                        break;
                    }
                }
            }
            else
                lines.push_back(line);
        }
    }

    string out_file = "cplib." + main;

    ofstream of(out_file);
    for (int i = lines.size() - 1; i >= 0; i--)
        of << lines[i] << "\n";
    of.close();
}

void input_file(string file) {}
void output_file(string file) {}
#endif
#endif

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

int N, V[25];
int same[25];
int memo[1 << 25];

string to_binary(int s) {
    string r = "";
    for (int i = 0; i < N; i++)
        if (s & (1 << i)) r += "1";
        else r += "0";
    return r;
}

int dp(int bs) {
    if (memo[bs] != -1) return memo[bs];
    int res = 0;
    int x = 0;
    while (!(bs & (1 << x))) x++;
    bool good = true;
    if (bs & (1 << (x + 1))) res = (res + dp(bs ^ (1 << x))) % MOD;
    for (int i = x + 1; i < N; ) {
        if (bs & (1 << i)) { i++; continue; }
        for (int j = i + 1; j < N; ) {
            if (bs & (1 << j)) { j++; continue; }
            int l = lcm(V[i], V[j]);
            if (l == V[x]) {
                ll tmp = dp(bs ^ (1 << x) ^ (1 << i) ^ (1 << j));
                if (V[i] != V[j]) tmp = tmp * same[i] % MOD * same[j] % MOD;
                else tmp = tmp * (same[i] * (same[i] - 1) / 2) % MOD;
                res = (res + tmp) % MOD;
            }
            j += same[j];
        }
        if (!(bs & (1 << i))) good = false;
        if (i == x + 1 && !(bs & (1 << i))) break;
        i += same[i];
    }
    if (good) res = 1;
    // cout << to_binary(bs) << " " << res << "\n";
    return memo[bs] = res;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> V[i];
    sort(V, V + N, [&](int a, int b) -> bool { return a > b; });

    for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1 || V[i] != V[i + 1]) same[i] = 1;
        else same[i] = same[i + 1] + 1;
        // cout << V[i] << " " << same[i] << "\n";
    }

    fill(memo, memo + (1 << 25) - 1, -1);
    cout << (ll) dp(1) * same[0] % MOD << "\n";
}

int main() {
    cplib("main.cpp");
    testcase("7 2 3 4 4 8 12 24", "2");
    testcase("3 7 7 7", "3");
    testcase("5 1 2 3 2 1", "0");
    testcase("13 1 1 1 1 1 1 1 1 1 1 1 1 1", "843230316");
    return test();
}
