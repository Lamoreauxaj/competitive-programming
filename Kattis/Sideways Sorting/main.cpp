#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> grid;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    bool first = true;
    while (cin >> R >> C, R || C) {
        if (!first) cout << "\n";
        first = false;
        grid.assign(R, "");
        for (int i = 0; i < R; i++)
            cin >> grid[i];
        vector<string> words;
        for (int i = 0; i < C; i++) {
            string r = "";
            for (int j = 0; j < R; j++)
                r += grid[j][i];
            words.push_back(r);
        }
        sort(words.begin(), words.end(), [&](const string& a, const string& b) -> bool {
            string ta = a;
            string tb = b;
            transform(ta.begin(), ta.end(), ta.begin(), ::tolower);
            transform(tb.begin(), tb.end(), tb.begin(), ::tolower);
            return ta < tb;
        });
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < words.size(); j++)
                cout << words[j][i];
            cout << "\n";
        }
    }

    return 0;
}
