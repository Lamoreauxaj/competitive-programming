#include <bits/stdc++.h>
using namespace std;

vector<string> grid;

// run bfs from S to K
int bfs() {
    vector<vector<bool>> visited(10, vector<bool>(10, false));
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (grid[i][j] == 'S')
                q.push({0, {i, j}});
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        int r = t.second.first, c = t.second.second;
        if (r < 0 || r >= 10 || c < 0 || c >= 10)
            continue;
        if (visited[r][c]) continue;
        visited[r][c] = true;
        if (grid[r][c] == '#') continue;
        if (grid[r][c] == 'K')
            return t.first;
        q.push({t.first + 1, {r - 1, c}});
        q.push({t.first + 1, {r + 1, c}});
        q.push({t.first + 1, {r, c - 1}});
        q.push({t.first + 1, {r, c + 1}});
    }
    return 1000000000;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    // input
    for (int i = 0; i < 10; i++) {
        string line; cin >> line;
        grid.push_back(line);
    }
    
    // run bfs
    int time = bfs();
    
    // output
    if (time > 15)
        cout << "Late: " << time - 15 << " minutes\n";
    else
        cout << "On time: " << time << " minutes\n";
    
    return 0;
}
