#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<int>> grid;

int main() {
    ios_base::sync_with_stdio(false);
    
    // input and find max element
    cin >> R >> C;
    grid.assign(R, vector<int>(C, 0));
    int ans = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j],
            ans = max(ans, grid[i][j]);
    
    // output
    cout << ans << "\n";
    
    return 0;
}
