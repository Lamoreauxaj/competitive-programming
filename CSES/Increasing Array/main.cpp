#include <bits/stdc++.h>
using namespace std;

int N, A[500010];

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // sum turns needed
    long long ans = 0;
    int last = 0;
    for (int i = 0; i < N; i++) {
        ans += max(0, last - A[i]);
        last = max(last, A[i]);
    }

    // output
    cout << ans << "\n";

    return 0;
}
