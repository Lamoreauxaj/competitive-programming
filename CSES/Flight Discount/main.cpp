#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> adj;

int main() {
    ios_base::sync_with_stdio(false);

    // input
    cin >> N >> M;
    adj.assign(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    // run dijkstra
    priority_queue<pair<int, pair<long long, bool>>, vector<pair<int, pair<long long, bool>>>, greater<pair<int, pair<long long, bool>>>> pq;
    vector<vector<long long>> dist(N + 1, vector<long long>(2, 1000000000000000LL));
    dist[1][0] = 0;
    pq.push({1, {0, 0}});
    while (!pq.empty()) {
        auto t = pq.top(); pq.pop();
        long long u = t.first, d = t.second.first, disc = t.second.second;
        if (d > dist[u][disc]) continue;
        for (auto p : adj[u]) {
            int v = p.first, w = p.second;
            if (d + w < dist[v][disc]) {
                dist[v][disc] = d + w;
                pq.push({v, {dist[v][disc], disc}});
            }
            if (!disc) {
                w /= 2;
                if (d + w < dist[v][1]) {
                    dist[v][1] = d + w;
                    pq.push({v, {dist[v][1], 1}});
                }
            }
        }
    }

    // output
    cout << dist[N][1] << "\n";

    return 0;
}
