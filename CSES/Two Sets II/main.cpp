#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;
 
int N, needed;
int memo[500][125000];
 
int dp(int pos, int sum) {
    if (pos == N)
        return sum == needed;
    if (pos * (pos + 1) / 2 < 2 * sum)
        return dp(pos, pos * (pos + 1) / 2 - sum);
    if (memo[pos][sum] != -1)
        return memo[pos][sum];
    if (sum + pos + 1 > needed)
        return memo[pos][sum] = dp(pos + 1, sum);
    return memo[pos][sum] = (dp(pos + 1, sum + pos + 1) + dp(pos + 1, sum)) % MOD;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> N;
 
    if (N * (N + 1) / 2 % 2 != 0) {
        cout << "0\n";
        return 0;
    }
    needed = N * (N + 1) / 4;
 
    fill(memo[0], memo[499] + 125000, -1);
    int ans = dp(1, 1);
 
    cout << ans << "\n";
 
    return 0;
}
