#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const vector<pair<int, int>> deltas = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int R, C;
vector<vector<int>> grid;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    cin >> R >> C;
    grid.assign(R, vector<int>(C));
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++)
        cin >> grid[i][j];

    typedef pair<int, pair<int, int>> Node;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<vector<int>> dist(R, vector<int>(C, INF));
    for (int i = 0; i < R; i++) {
        dist[i][0] = grid[i][0];
        pq.push({dist[i][0], {i, 0}});
    }
    while (!pq.empty()) {
        Node t = pq.top(); pq.pop();
        if (dist[t.second.first][t.second.second] < t.first) continue;
        for (auto delta : deltas) {
            pair<int, int> nxt = {t.second.first + delta.first, t.second.second + delta.second};
            if (nxt.first < 0 || nxt.second < 0 || nxt.first >= R || nxt.second >= C) continue;
            int d = max(grid[nxt.first][nxt.second], t.first);
            if (d < dist[nxt.first][nxt.second]) {
                dist[nxt.first][nxt.second] = d;
                pq.push({dist[nxt.first][nxt.second], nxt});
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < R; i++)
        ans = min(ans, dist[i][C - 1]);
    cout << ans << "\n";

    return 0;
}
