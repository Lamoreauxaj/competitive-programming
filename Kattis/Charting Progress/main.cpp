#include <bits/stdc++.h>
using namespace std;

vector<string> grid;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    string line;
    while (true) {
        grid.clear();
        while (getline(cin, line)) {
            if (line == "") break;
            grid.push_back(line);
        }
        if (grid.empty()) break;

        vector<int> heights;
        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] == '*')
                    heights.push_back(j);
            }
        }
        sort(heights.begin(), heights.end(), [&](int a, int b) -> bool {
            return a > b;
        });
        for (int j = 0; j < grid.size(); j++) {
            for (int i = 0; i < heights.size(); i++) {
                if (j == heights[i]) cout << "*";
                else cout << ".";
            }
            cout << "\n";
        }

    }

    return 0;
}
