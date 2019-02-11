#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj, child;
vector<int> depth;

// construct tree
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

// calculate maximum depth at each subtree
int max_depth(int pos) {
	int ans = 0;
	for (int i : child[pos]) {
		ans = max(max_depth(i) + 1, ans);
	}
	return depth[pos] = ans;
}

// find max distance to another node for each node
vector<int> ans;
void recurse(int pos, int prev) {
	ans[pos] = max(depth[pos], prev);
	int max_child = -10, max_index = -1;
	int second_max_child = -10;
	for (int i : child[pos]) {
		if (depth[i] > max_child) {
			second_max_child = max_child;
			max_child = depth[i];
			max_index = i;
		}
		else {
			if (depth[i] > second_max_child) {
				second_max_child = depth[i];
			}
		}
	}
	for (int i : child[pos]) {
		int next_prev = 1 + prev;
		if (max_index == i)
			next_prev = max(next_prev, second_max_child + 2);
		else
			next_prev = max(next_prev, max_child + 2);
		recurse(i, next_prev);
	}
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

	// calculate max depths
	depth.assign(N, 0);
	max_depth(0);

	// find maximum distance
	ans.assign(N, 0);
	recurse(0, 0);

	// output
	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << "\n";

	return 0;
}
