#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;
const int MOD = 1000000007;
const ld EPS = 1e-9;
const ld PI = acos(-1);

#define x first
#define y second

int N, P[400010];
vector<int> val;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(10);

    int TC; cin >> TC;
    while (TC--) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> P[i];
        val.clear();
        int cnt = 1;
        for (int i = 1; i <= N; i++) {
            if (i == N || P[i] != P[i - 1]) {
                val.push_back(cnt);
                // cout << cnt << " ";
                cnt = 1;
            }
            else cnt++;
        }
        // cout << "\n";


        int g = -1, s = -1, b = -1;
        int gc = 0, sc = 0, bc = 0;
        int pg = 0, ps = 0, pb = 0;
        while (g + 1 < val.size()) {
            g++;
            gc += val[g];
            sc -= val[g];
            if (s < g) s = g, sc = 0;
            while ((sc == 0 || gc >= sc) && s + 1 < val.size()) sc += val[++s], bc -= val[s];
            if (b < s) b = s, bc = 0;
            while ((bc == 0 || gc >= bc) && b + 1 < val.size()) bc += val[++b];
            while (b + 1 < val.size() && (gc + bc + sc + val[b + 1]) * 2 <= N) bc += val[++b];
            if ((gc + bc + sc) * 2 <= N && sc > 0 && bc > 0 && gc > 0 && gc < sc && gc < bc) {
                pg = gc;
                ps = sc;
                pb = bc;
            }
        }

        cout << pg << " " << ps << " " << pb << "\n";
    }

    return 0;
}
