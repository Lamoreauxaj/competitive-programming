#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b; long long c;
};

int N, M;
vector<Edge> edges;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges.push_back(Edge{a - 1, b - 1, c});
    }

    vector<long long> d(N);
    vector<int> p(N, -1);
    int found;
    for (int i = 0; i < N; i++) {
        found = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.c < d[e.b]) {
                d[e.b] = d[e.a] + e.c;
                p[e.b] = e.a;
                found = e.b;
            }
        }
    }

    if (found != -1) {
        cout << "YES\n";

        for (int i = 0; i < N; i++)
            found = p[found];
        vector<int> cycle;
        for (int v = found; ; v = p[v]) {
            cycle.push_back(v);
            if (v == found && cycle.size() > 1)
                break;
        }
        bool first = true;
        reverse(cycle.begin(), cycle.end());
        for (int v : cycle) {
            if (!first) cout << " ";
            first = false;
            cout << v + 1;
        }
        cout << "\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
