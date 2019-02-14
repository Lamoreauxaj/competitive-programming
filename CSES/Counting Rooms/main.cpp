#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> grid;
vector<vector<bool>> visit;

void flood(int r, int c) {
    if (r < 0 || c < 0 || r >= R || c >= C) return;
    if (grid[r][c] == '#') return;
    if (visit[r][c]) return;
    visit[r][c] = 1;
    flood(r + 1, c);
    flood(r - 1, c);
    flood(r, c + 1);
    flood(r, c - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> R >> C;
    grid.assign(R, "");
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    // flood fill rooms
    visit.assign(R, vector<bool>(C, false));
    int rooms = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] != '#' && !visit[i][j]) {
                flood(i, j);
                rooms++;
            }
        }
    }

    // output
    cout << rooms << "\n";

    return 0;
}
