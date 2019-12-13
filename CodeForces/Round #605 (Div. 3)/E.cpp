#include "cplib.cpp"

int N, A[200010];
bool vis[200010];
int res[200010];
vector<int> adj[200010];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) {
        if (i - A[i] >= 0) adj[i - A[i]].push_back(i);
        if (i + A[i] < N) adj[i + A[i]].push_back(i);
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) if (A[i] % 2 != 0) q.push({i, 0});
    fill(res, res + N, -1);
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        if (vis[t.x]) continue;
        vis[t.x] = 1;
        if (A[t.x] % 2 == 0) res[t.x] = t.y;
        for (int i : adj[t.x]) q.push({i, t.y + 1});
    }
    fill(vis, vis + N, 0);
    for (int i = 0; i < N; i++) if (A[i] % 2 == 0) q.push({i, 0});
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        if (vis[t.x]) continue;
        vis[t.x] = 1;
        if (A[t.x] % 2 != 0) res[t.x] = t.y;
        for (int i : adj[t.x]) q.push({i, t.y + 1});
    }
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}

int main() {
    cplib("E.cpp");
    testcase("10 4 5 7 6 7 5 4 4 6 4", "1 1 1 2 -1 1 1 3 1 1");
    return test();
}