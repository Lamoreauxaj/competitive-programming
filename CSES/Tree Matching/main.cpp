#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;
vector<vector<int>> child;
vector<int> matching, sum_matching;

vector<bool> visit;
void construct_tree(int pos) {
    for (int i : adj[pos]) {
        if (!visit[i]) {
            visit[i] = 1;
            child[pos].push_back(i);
            construct_tree(i);
        }
    }
}

void max_matching(int pos) {
    for (int i : child[pos])
        max_matching(i);
    for (int i : child[pos])
        sum_matching[pos] += matching[i];
    matching[pos] = sum_matching[pos];
    for (int i : child[pos]) {
        matching[pos] = max(matching[pos], sum_matching[pos] - matching[i] + 1 + sum_matching[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N;
    adj.assign(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // construct tree
    child.assign(N, vector<int>());
    visit.assign(N, 0);
    visit[0] = 1;
    construct_tree(0);

    // recursively calculate matchings
    matching.assign(N, 0);
    sum_matching.assign(N, 0);
    max_matching(0);

    // output
    cout << matching[0] << "\n";

    return 0;
}
