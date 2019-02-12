#include <bits/stdc++.h>
using namespace std;

int N, A[200010];
int lis[200010], p[200010];

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // run lis
    p[0] = 0;
    for (int i = 1; i <= N + 1; i++)
        p[i] = 1000000001;
    for (int i = 0; i < N; i++) {
        int low = 0, high = N;
        while (low < high) {
            int mid = (low + high) / 2;
            if (p[mid] < A[i] && p[mid + 1] >= A[i])
                break;
            else if (p[mid] < A[i])
                low = mid + 1;
            else
                high = mid - 1;
        }

        int len = (low + high) / 2 + 1;
        lis[i] = len;
        p[len] = min(p[len], A[i]);
    }

    // find max lis
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, lis[i]);

    // output
    cout << ans << "\n";

    return 0;
}
