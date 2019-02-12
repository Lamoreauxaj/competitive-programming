#include <bits/stdc++.h>
using namespace std;

long long Y, X;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    int TC; cin >> TC;
    while (TC--) {
        // input
        cin >> Y >> X;

        // calculate ring
        long long r = max(Y, X);

        // calculate value
        long long ans = 0;
        if (r % 2 == 1)
            ans = r * r - (Y - 1) - (r - X);
        else
            ans = r * r - (X - 1) - (r - Y);

        // output
        cout << ans << "\n";
    }

    return 0;
}
