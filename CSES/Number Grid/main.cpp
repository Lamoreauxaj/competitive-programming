#include <bits/stdc++.h>
using namespace std;

int X, Y;

int find(int x, int y) {
    if (x == 1 || y == 1) return x + y - 2;
    if (x == 2 && y == 2) return 0;
    return find((x - 1) % 2 + 1, (y - 1) % 2 + 1) + 2 * (find((x + 1) / 2, (y + 1) / 2));
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> X >> Y;

    cout << find(X, Y) << "\n";

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << setw(3) << find(i, j) << " ";
        }
        cout << "\n";
    }

    int SZ = 25;
    vector<vector<int>> grid(SZ, vector<int>(SZ));
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            unordered_set<int> used;
            for (int k = 0; k < i; k++)
                used.insert(grid[k][j]);
            for (int k = 0; k < j; k++)
                used.insert(grid[i][k]);
            int k;
            for (k = 0; used.count(k); k++);
            grid[i][j] = k;
        }
    }
    for (auto i : grid) {
        for (int j : i) cout << setw(3) << j << " "; cout << "\n";
    }

    return 0;
}
