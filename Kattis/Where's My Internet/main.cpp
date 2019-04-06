#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> conn;

void flood(int i) {
    if (conn[i]) return;
    conn[i] = true;
    for (int k : adj[i])
        flood(k);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    conn.assign(N, false);
    adj.assign(N, {});
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    flood(0);

    bool found = false;
    for (int i = 0; i < N; i++)
        if (!conn[i])
            cout << i + 1 << "\n", found = true;

    if (!found) cout << "Connected\n";

    return 0;
}
