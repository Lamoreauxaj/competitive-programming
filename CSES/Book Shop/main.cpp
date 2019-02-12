#include <bits/stdc++.h>
using namespace std;

int N, W, knap[100010], wt[1010], val[1010];

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N >> W;
    for (int i = 0; i < N; i++)
        cin >> wt[i];
    for (int i = 0; i < N; i++)
        cin >> val[i];

    // run knapsack
    for (int i = 0; i < N; i++) {
        for (int j = W; j >= wt[i]; j--)
            knap[j] = max(knap[j], knap[j - wt[i]] + val[i]);
    }

    // output
    cout << knap[W] << "\n";

    return 0;
}
