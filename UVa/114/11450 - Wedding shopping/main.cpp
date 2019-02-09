#include <bits/stdc++.h>
using namespace std;

int N, M; // number of garments and total money
vector<int> prices[25]; // prices of each garment

int memo[25][250];

// dp function for maximum money
int dp(int gar, int money) {
    if (gar == N)
        return 0;
    if (memo[gar][money] != -1)
        return memo[gar][money];
    int ans = -1000000000;
    for (int i = 0; i < prices[gar].size(); i++) { // try all garment prices
        if (prices[gar][i] <= money)
            ans = max(ans, dp(gar + 1, money - prices[gar][i]) + prices[gar][i]);
    }
    return memo[gar][money] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("1.in", "r", stdin);

    int TC; cin >> TC;
    while (TC--) {
        // input
        cin >> M >> N;
        fill(prices, prices + N, vector<int>());
        for (int i = 0; i < N; i++) {
            int K; cin >> K;
            for (int j = 0; j < K; j++) {
                int a; cin >> a;
                prices[i].push_back(a);
            }
        }

        // run dp
        fill(memo[0], memo[24] + 250, -1);
        int ans = dp(0, M);

        // output
        if (ans < 0)
            cout << "no solution\n";
        else
            cout << ans << "\n";
    }

    return 0;
}
