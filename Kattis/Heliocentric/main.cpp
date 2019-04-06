#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int a, b;
    int tc = 0;
    while (++tc, cin >> a >> b) {
        cout << "Case " << tc << ": ";
        int x = 365 - a;
        if (a == 0) x = 0;
        while ((b + x) % 687 != 0)
            x += 365;
        cout << x << "\n";
    }

    return 0;
}
