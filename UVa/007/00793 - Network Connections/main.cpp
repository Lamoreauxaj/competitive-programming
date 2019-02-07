#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> par, rnk;

// find parent element of set containing i
int find(int i) {
	return (par[i] == i ? i : par[i] = find(par[i]));
}

// join i and j in union find
void join(int i, int j) {
	if (find(i) != find(j)) {
		int x = find(i), y = find(j);
		if (rnk[x] > rnk[y]) par[y] = x;
		else {
			par[x] = y;
			if (rnk[x] == rnk[y]) rnk[y]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("test.in", "r", stdin);

	int TC; cin >> TC;
	while (TC--) {
		// input
		cin >> N;

		// construct union find disjoint set
		par.assign(N + 1, 0);
		for (int i = 1; i <= N; i++)
			par[i] = i;
		rnk.assign(N + 1, 0);

		// process queries
		int succ = 0, fail = 0;
		string line;
		getline(cin, line);
		while (getline(cin, line)) {
			if (line == "") break;
			stringstream ss(line);
			char act; int a, b;
			ss >> act >> a >> b;

			if (act == 'c')
				join(a, b);
			else {
				if (find(a) == find(b))
					succ++;
				else
					fail++;
			}
		}

		// output
		cout << succ << "," << fail << "\n";
		if (TC) cout << "\n";
	}

	return 0;
}
