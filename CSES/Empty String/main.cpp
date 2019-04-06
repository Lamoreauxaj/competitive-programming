#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000 + 7;

string S;

int cmemo[1001][1001];

int choose(int n, int r) {
    if (n < r) return 0;
    if (n == r || r == 0) return 1;
    if (cmemo[n][r] != -1) return cmemo[n][r];
    return cmemo[n][r] = (choose(n - 1, r - 1) + choose(n - 1, r)) % MOD;
}

int memo[501][501];

int dp(int l, int r) {
    if (l > r) return 1;
    if (l == r) return 0;
    if (l == r - 1) return S[l] == S[r] ? 1 : 0;
    if (memo[l][r] != -1) return memo[l][r];
    unordered_set<char> odds;
    int ans = 0;
    for (int j = l; j <= r; j++) {
        if (odds.count(S[j])) odds.erase(S[j]);
        else odds.insert(S[j]);
        if (odds.empty() && S[j] == S[l] && j != l) {
            int nl = (j - l + 1) / 2;
            int nr = (r - j) / 2;
            ans += ((long long) dp(l + 1, j - 1) * dp(j + 1, r)) % MOD * choose(nr + nl, nl) % MOD;
            ans %= MOD;
        }
    }
    return memo[l][r] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    fill(memo[0], memo[500] + 501, -1);
    fill(cmemo[0], cmemo[1000] + 1001, -1);

    cin >> S;

    cout << dp(0, S.size() - 1) << "\n";

    return 0;
}
