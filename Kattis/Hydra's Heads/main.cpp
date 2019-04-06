#include <bits/stdc++.h>
using namespace std;

int H, T;

int main() {
    ios_base::sync_with_stdio(false);

    while (cin >> H >> T, H || T) {
        int ans = 0;
        if (T % 2 == 1) ans++, T++;

        if (T == 0 && H % 2 == 1) {
            cout << "-1\n";
            continue;
        }

        ans += T / 2;
        H += T / 2;
        if (H % 2 != 0)
            ans += 3, H++;
        ans += H / 2;

        cout << ans << "\n";
    }

    return 0;
}
