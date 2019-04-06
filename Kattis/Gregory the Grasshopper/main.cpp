#include <bits/stdc++.h>
using namespace std;

int R, C;
pair<int, int> grass, leaf;

int main() {
    ios_base::sync_with_stdio(false);

    while (cin >> R >> C >> grass.first >> grass.second >> leaf.first >> leaf.second) {

        typedef pair<int, pair<int, int>> Node;
        queue<Node> q;
        q.push(Node(0, grass));
        bool found = false;
        vector<vector<bool>> visited(R + 1, vector<bool>(C + 1));
        while (!q.empty()) {
            Node t = q.front(); q.pop();
            if (t.second.first <= 0 || t.second.second <= 0 || t.second.first > R || t.second.second > C) continue;
            if (visited[t.second.first][t.second.second]) continue;
            visited[t.second.first][t.second.second] = true;
            if (t.second == leaf) {
                cout << t.first << "\n";
                found = true;
            }
            q.push(Node(t.first + 1, {t.second.first - 1, t.second.second - 2}));
            q.push(Node(t.first + 1, {t.second.first - 1, t.second.second + 2}));
            q.push(Node(t.first + 1, {t.second.first + 1, t.second.second - 2}));
            q.push(Node(t.first + 1, {t.second.first + 1, t.second.second + 2}));
            q.push(Node(t.first + 1, {t.second.first - 2, t.second.second - 1}));
            q.push(Node(t.first + 1, {t.second.first + 2, t.second.second - 1}));
            q.push(Node(t.first + 1, {t.second.first - 2, t.second.second + 1}));
            q.push(Node(t.first + 1, {t.second.first + 2, t.second.second + 1}));
        }

        if (!found) cout << "impossible\n";

    }

    return 0;
}
