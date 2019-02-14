#include <bits/stdc++.h>
using namespace std;

const vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};

int R, C;
vector<string> grid;
vector<vector<pair<int, int>>> parent;
vector<vector<int>> dist;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> R >> C;
    grid.assign(R, "");
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    // run bfs
    queue<pair<pair<int, int>, int>> q;
    dist.assign(R, vector<int>(C, 1000000));
    parent.assign(R, vector<pair<int, int>>(C, {-1, -1}));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] == 'A')
                dist[i][j] = 0,
                q.push({{i, j}, 0});
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        int d = t.second;
        int r = t.first.first, c = t.first.second;
        for (int i = 0; i < 4; i++) {
            int rr = r + dr[i], cc = c + dc[i];
            if (rr >= 0 && cc >= 0 && rr < R && cc < C) {
                if (grid[rr][cc] != '#' && dist[rr][cc] == 1000000) {
                    parent[rr][cc] = {r, c};
                    dist[rr][cc] = d + 1;
                    q.push({{rr, cc}, d + 1});
                }
            }
        }
    }

    // find ending position
    int r = 0, c = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] == 'B')
                r = i, c = j;

    // output
    if (dist[r][c] == 1000000)
        cout << "NO\n";
    else {
        cout << "YES\n";
        cout << dist[r][c] << "\n";
        string res = "";
        while (parent[r][c].first != -1) {
            int dr = r - parent[r][c].first;
            int dc = c - parent[r][c].second;
            if (dr == -1)
                res += "U";
            else if (dr == 1)
                res += "D";
            else if (dc == -1)
                res += "L";
            else
                res += "R";
            int tr = parent[r][c].first, tc = parent[r][c].second;
            r = tr, c = tc;
        }
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }

    return 0;
}
