#include "cplib.cpp"

void solve() {
    int N, K; cin >> N >> K;
    set<char> good;
    string S; cin >> S;
    for (int i = 0; i < K; i++) {
        char c; cin >> c;
        good.insert(c);
    }
    ll res = 0;
    int cnt = 0;
    for (int i = 0; i <= N; i++) {
        if (i == N || !good.count(S[i])) {
            res += (ll) cnt * (cnt + 1) / 2;
            cnt = 0;
        }
        else cnt++;
    }
    cout << res << "\n";
}

int main() {
    cplib("C.cpp");
    testcase("7 2\nabacaba\na b\n", "12");
    testcase("10 3 sadfaasdda f a d", "21");
    testcase("7 1 aaaaaaa b", "0");
    return test();
}