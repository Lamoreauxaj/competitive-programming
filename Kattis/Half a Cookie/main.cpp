#include <bits/stdc++.h>
using namespace std;

double r, x, y;

int main() {
    ios_base::sync_with_stdio(false);

    while (cin >> r >> x >> y) {
        double d = x * x + y * y;
        if (d > r * r) { cout << "miss\n"; continue; }
        double ang = acos((4 * (r * r - d) - r * r - r * r) / (-2 * r * r));
        double tri = r * r * sin(ang) / 2;
        double sec = r * r * ang / 2;
        double seg = sec - tri;
        cout << fixed << setprecision(6) << acos(-1) * r * r - seg << " " << seg << "\n";
    }

    return 0;
}
