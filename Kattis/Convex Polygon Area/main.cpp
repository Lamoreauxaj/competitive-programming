#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> poly;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    int TC; cin >> TC;
    while (TC--) {
        int N; cin >> N;
        poly.assign(N, {0, 0});
        for (int i = 0; i < N; i++)
            cin >> poly[i].first >> poly[i].second;

        int area = 0;
        for (int i = 0; i < N; i++) {
            auto p1 = poly[i];
            auto p2 = poly[(i + 1) % N];
            area += p1.first * p2.second - p1.second * p2.first;
        }
        if (area % 2 == 0)
            cout << area / 2 << "\n";
        else
            cout << fixed << setprecision(1) << area / 2.0 << "\n";
    }

    return 0;
}
