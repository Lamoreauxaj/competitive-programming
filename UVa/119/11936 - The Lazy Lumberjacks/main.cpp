#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("1.in", "r", stdin);

	int TC; cin >> TC;
	while (TC--) {
		// input
		int a, b, c; cin >> a >> b >> c;

		// check triangle inequality
		if (a + b > c && a + c > b && b + c > a)
			cout << "OK\n";
		else
			cout << "Wrong!!\n";
	}	

	return 0;
}
