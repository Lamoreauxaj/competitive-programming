#include <bits/stdc++.h>
using namespace std;

double x1, x2, x3;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("1.in", "r", stdin);

    while (cin >> x1 >> x2 >> x3) {
        // calculate side lengths
        double a = sqrt((2 * x2 * x2 + 2 * x3 * x3 - x1 * x1) / 9) * 2;
        double b = sqrt((2 * x1 * x1 + 2 * x3 * x3 - x2 * x2) / 9) * 2;
        double c = sqrt((2 * x1 * x1 + 2 * x2 * x2 - x3 * x3) / 9) * 2;

        // calculate area
        double s = (a + b + c) / 2;
        double A = sqrt(s * (s - a) * (s - b) * (s - c));

        // check for invalid triangles
        if (a + b <= c || a + c <= b || b + c <= a || a >= s || b >= s || c >= s || x1 * x1 >= 2 * x2 * x2 + 2 * x3 * x3 || x2 * x2 >= 2 * x1 * x1 + 2 * x3 * x3 || x3 * x3 >= 2 * x1 * x1 + 2 * x2 * x2)
            A = -1;

        // output
        cout << fixed << setprecision(3) << A << "\n";
    }

    return 0;
}
