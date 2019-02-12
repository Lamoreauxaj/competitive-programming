#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N;

    // address special cases
    if (N == 1)
        cout << "1\n";
    else if (N == 2 || N == 3)
        cout << "NO SOLUTION\n";
    else if (N == 4)
        cout << "3 1 4 2\n";
    else {
        int l = 2, r = N;
        while ((r - l) >= 2) {
            cout << r << " " << l << " ";
            l++, r--;
        }
        if (r != l)
            cout << r << " " << 1 << " " << l << "\n";
        else
            cout << 1 << " " << l << "\n";
    }

    return 0;
}
