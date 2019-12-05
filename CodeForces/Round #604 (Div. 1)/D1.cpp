#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;
const int MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1);

#define x first
#define y second

string S;

pair<ll, ll> memo[2010][2010];
pair<ll, ll> dp(int pos, int open) {
    if (pos == -1) {
        if (open == 0) return {0, 1};
        else return {0, 0};
    }
    if (memo[pos][open].first != -1) return memo[pos][open];
    pair<ll, ll> res = {0, 0};
    if (S[pos] == '?' || S[pos] == ')') {
        pair<ll, ll> r = dp(pos - 1, open + 1);
        res.first = (res.first + r.first + r.second) % MOD;
        res.second = (res.second + r.second) % MOD;
        if (open == 0) {
            r = dp(pos - 1, 0);
            res.first = (res.first + r.first) % MOD;
            res.second = (res.second + r.second) % MOD;
        }
    }
    if (S[pos] == '?' || S[pos] == '(') {
        if (open > 0) {
            pair<ll, ll> r = dp(pos - 1, open - 1);
            res.first = (res.first + r.first) % MOD;
            res.second = (res.second + r.second) % MOD;
        }
    }
    cout << pos << " " << open << " " << res.first << ":" << res.second << "\n";
    return memo[pos][open] = res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(10);

    cin >> S;

    for (int i = 0; i < 2010; i++)
        for (int j = 0; j < 2010; j++)
            memo[i][j].first = -1;

    pair<ll, ll> res;
    for (int i = 0; i <= S.size(); i++) {
        pair<ll, ll> r = dp(S.size() - 1, i);
        res.first = (res.first + r.first) % MOD;
        res.second = (res.second + r.second) % MOD;
    }

    cout << res.first << "\n";
    cout << res.second << "\n";

    return 0;
}
