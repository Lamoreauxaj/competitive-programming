#include <bits/stdc++.h>
using namespace std;

const long double PI = acos(-1);
const long double EPS = 1e-8;

#define x first
#define y second

int N;
pair<int, int> pts[2510];

double norm(double a) {
    while (a < 0) a += 2 * PI;
    return a;
}

int quadrant(long long dy, long long dx) {
    if (dx > 0 && dy > 0) return 0;
    if (dx == 0 && dy > 0) return 1;
    if (dx < 0 && dy > 0) return 2;
    if (dy == 0 && dx < 0) return 3;
    if (dx < 0 && dy < 0) return 4;
    if (dx == 0 && dy < 0) return 5;
    if (dx > 0 && dy < 0) return 6;
    if (dy == 0 && dx > 0) return 7;
    return -1;
}

bool ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    pair<long long, long long> ab, ac;
    ab.x = b.x - a.x;
    ab.y = b.y - a.y;
    ac.x = c.x - a.x;
    ac.y = c.y - a.y;
    return ac.x * ab.y - ac.y * ab.x > 0;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> pts[i].x >> pts[i].y;

    long long tot = 0;
    for (int i = 0; i < N; i++) {
        vector<pair<double, pair<int, int>>> s;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                int dx = pts[j].x - pts[i].x;
                int dy = pts[j].y - pts[i].y;
                s.push_back({atan2(dy, dx), pts[j]});
            }
        }
        // sort(s.begin(), s.end());
        sort(s.begin(), s.end(), [&](const pair<double, pair<int, int>>& a, const pair<double, pair<int, int>>& b) -> bool {
            long long dx1 = a.y.x - pts[i].x;
            long long dy1 = a.y.y - pts[i].y;
            long long dx2 = b.y.x - pts[i].x;
            long long dy2 = b.y.y - pts[i].y;
            int q1 = quadrant(dy1, dx1);
            int q2 = quadrant(dy2, dx2);
            if (q1 != q2) return q1 < q2;
            return dy1 * dx2 < dy2 * dx1;
        });

        int r = 1;

        for (int l = 0; l < s.size(); l++) {
            if (r == l) r = (l + 1) % s.size();
            while (r != l && ccw(pts[i], s[r].y, s[l].y)) r = (r + 1) % s.size();

            // cout << s[l].y.x << "," << s[l].y.y << " " << s[r].y.x << "," << s[r].y.y << " are paired\n";

            int p = l;
            long long d = r - l - 1;
            while (d < 0) d += s.size();
            tot += d * (d - 1) / 2;
            tot += (N - 2 - d) * (N - 3 - d) / 2;
            // cout << pts[i].x << "," << pts[i].y << " -> " << s[p].y.x << "," << s[p].y.y << " has " << d << " points\n";
        }
    }

    long long pos = (long long) N * (N - 1) * (N - 2) * (N - 3) / 24;

    // assert(tot % 2 == 0);
    tot /= 2;
    tot -= 3 * pos;
    // assert(tot >= 0);
    tot = pos - tot;
    // assert(tot >= 0);
    // assert(tot * (N - 4) % 2 == 0);
    cout << tot * (N - 4) / 2 << "\n";

    return 0;
}
