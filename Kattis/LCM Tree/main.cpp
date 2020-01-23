#include "cplib.cpp"

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