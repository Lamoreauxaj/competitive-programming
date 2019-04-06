#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<long double, long double>> pts;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    pts.assign(N, {0, 0});
    for (int i = 0; i < N; i++)
        cin >> pts[i].first >> pts[i].second;

    long double ans = 0;
    for (int i = 1; i < N; i++)
        ans += (pts[i].second + pts[i - 1].second) / 2 * (pts[i].first - pts[i - 1].first) / 1000;

    cout << fixed << setprecision(8) << ans << "\n";

    return 0;
}
