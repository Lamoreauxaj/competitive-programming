#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj, child;
vector<int> height;

// construct the tree rooted at 0
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

// calculate height of each node
int find_height(int pos) {
    int res = 0;
    for (int i : child[pos])
        res = max(res, find_height(i) + 1);
    return height[pos] = res;
}

// recursively find the maximum distance
int max_dist(int pos) {
    int max_child = -1, second_max_child = -1;
    int ans = 0;
    for (int i : child[pos]) {
        if (height[i] > max_child) {
            second_max_child = max_child;
            max_child = height[i];
        } else if (height[i] > second_max_child) {
            second_max_child = height[i];
        }
        ans = max(ans, max_dist(i));
    }
    ans = max(ans, max_child + second_max_child + 3);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N;
    adj.assign(N, vector<int>());
    child.assign(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // construct tree
    visit.assign(N, 0);
    visit[0] = 1;
    construct_tree(0);

    // find height of each node
    height.assign(N, 0);
    find_height(0);

    // find maximum distance
    cout << max_dist(0) - 1 << "\n";

    return 0;
}
