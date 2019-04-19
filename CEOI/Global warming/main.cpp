#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200000
#define INF 1000000001

int N, X;
int nums[MAX_N], help[2][MAX_N + 1], lis[2][MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    cin >> N >> X;
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    fill(help[0], help[0] + MAX_N + 1, 2 * INF);
    help[0][0] = -INF;
    fill(help[1], help[1] + MAX_N + 1, 2 * INF);
    help[1][0] = -INF;
    
    for (int i = 0; i < N; i++) {
        for (int j = 1; j >= 0; j--) {
            if (j == 0) {
                int lo = 0, hi = N - 1, k = 0;
                while (lo <= hi) {
                    int m = (lo + hi) / 2;
                    if (help[0][m] < nums[i])
                        k = m, lo = m + 1;
                    else
                        hi = m - 1;
                }

                lis[0][i] = 1 + k;
                help[0][lis[0][i]] = min(help[0][lis[0][i]], nums[i]);
                help[1][lis[0][i]] = min(help[1][lis[0][i]], nums[i] - X);
            }
            else {
                int lo = 0, hi = N - 1, k = 0;
                while (lo <= hi) {
                    int m = (lo + hi) / 2;
                    if (help[1][m] < nums[i])
                        k = m, lo = m + 1;
                    else
                        hi = m - 1;
                }

                lis[1][i] = k + 1;
                help[1][k + 1] = min(help[1][k + 1], nums[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, max(lis[0][i], lis[1][i]));
    }
    cout << ans << "\n";

    return 0;
}
