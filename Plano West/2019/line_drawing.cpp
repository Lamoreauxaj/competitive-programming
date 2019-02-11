#include <bits/stdc++.h>
using namespace std;

int R, C, Q;
vector<vector<int>> grid;

int main() {
    ios_base::sync_with_stdio(false);
    
    // input
    cin >> R >> C >> Q;
    grid.assign(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j];
    
    // find preprocessed sets of possible values
    set<int> max_evens, max_odds, max_indep;
    for (int i = 0; i < R; i++) {
        int sum = 0, two_front = 0, two_back = 0;
        for (int j = 0; j < C; j++)
            sum += grid[i][j];
        for (int j = 0; j < C && grid[i][j] == 2; j++)
            two_front++;
        for (int j = C - 1; j >= 0 && grid[i][j] == 2; j--)
            two_back++;
        if (sum % 2 == 0)
            max_evens.insert(sum);
        else
            max_odds.insert(sum);
        max_indep.insert(sum - min(two_front, two_back) * 2);
    }
    for (int i = 0; i < C; i++) {
        int sum = 0, two_front = 0, two_back = 0;
        for (int j = 0; j < R; j++)
            sum += grid[j][i];
        for (int j = 0; j < R && grid[j][i] == 2; j++)
            two_front++;
        for (int j = R - 1; j >= 0 && grid[j][i] == 2; j--)
            two_back++;
        if (sum % 2 == 0)
            max_evens.insert(sum);
        else
            max_odds.insert(sum);
        max_indep.insert(sum - min(two_front, two_back) * 2);
    }
    
    // process queries
    for (int i = 0; i < Q; i++) {
        int P; cin >> P;
        
        bool works = false;
        if (P % 2 == 0 && max_evens.lower_bound(P) != max_evens.end())
            works = true;
        else if (P % 2 != 0 && max_odds.lower_bound(P) != max_odds.end())
            works = true;
        if (!works && max_indep.lower_bound(P) != max_indep.end())
            works = true;
        
        if (works)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
