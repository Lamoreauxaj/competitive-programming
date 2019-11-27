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

int N, M, deg[510];
vector<int> adj[510];
char res[510];

int ac = 0, cc = 0, bc = 0;
void flood(int p, char s) {
    if (res[p] >= 'a') return;
    res[p] = s;
    if (s == 'a') ac++;
    else cc++;
    for (int j : adj[p]) flood(j, s);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(10);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
        deg[a]++;
        deg[b]++;
    }


    for (int i = 1; i <= N; i++) {
        if (deg[i] == N - 1) {
            res[i] = 'b';
            bc++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (res[i] != 'b') {
            flood(i, 'a');
            break;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (res[i] != 'b' && res[i] != 'a') {
            flood(i, 'c');
            break;
        }
    }

    bool works = true;

    for (int i = 1; i <= N; i++) {
        if (res[i] == 'a' && deg[i] != ac - 1 + bc) works = false;
        if (res[i] == 'c' && deg[i] != cc - 1 + bc) works = false;
        if (res[i] < 'a') works = false;
    }

    if (!works) cout << "No\n";
    else {
        cout << "Yes\n";
        for (int i = 1; i <= N; i++) cout << res[i];
        cout << "\n";
    }

    return 0;
}
