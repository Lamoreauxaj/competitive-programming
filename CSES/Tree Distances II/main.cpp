#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;
vector<vector<int>> child;
vector<int> size;
vector<long long> below, above;

// construct rooted tree
vector<bool> visit;
void construct_tree(int pos) {
	for (int i : adj[pos]) {
		if (!visit[i]) {
			child[pos].push_back(i);
			visit[i] = 1;
			construct_tree(i);
		}
	}
}

// compute size of subtree using dfs
int recurse_size(int pos) {
	int sum = 1;
	for (int i : child[pos])
		sum += recurse_size(i);
	return size[pos] = sum;
}

// compute sum of distances in sub tree
long long recurse_below(int pos) {
	long long sum = 0;
	for (int i : child[pos])
		sum += recurse_below(i) + size[i];
	return below[pos] = sum;
}

// compute sum of distances above sub tree
void recurse_above(int pos, long long sum_above) {
	long long sum_children = 0, size_children = 0;
	for (int i : child[pos]) {
		sum_children += below[i] + size[i];
		size_children += size[i];
	}
	for (int i : child[pos]) {
		above[i] = sum_children + sum_above - below[i] - size[i] + size_children + 1 - size[i] + N - size[pos];
		recurse_above(i, above[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);

	// input
	cin >> N;
	adj.assign(N, vector<int>());
	child.assign(N, vector<int>());
	visit.assign(N, 0);
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// construct tree
	visit[0] = 1;
	construct_tree(0);

	// for every node compute size of subtree
	size.assign(N, 0);
	recurse_size(0);

	// compute sum of distances below
	below.assign(N, 0);
	recurse_below(0);

	// compute sum of distances above
	above.assign(N, 0);
	recurse_above(0, 0);

	// output
	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << below[i] + above[i];
	}
	cout << "\n";

	return 0;
}