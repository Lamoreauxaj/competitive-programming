#include <bits/stdc++.h>
using namespace std;

// sieve for primes below 3000
vector<bool> is_prime;
void sieve() {
	is_prime.assign(3000, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 4; i < 3000; i += 2)
		is_prime[i] = false;
	for (int i = 3; i < 3000; i += 2) {
		if (is_prime[i]) {
			for (int j = i * i; j < 3000; j += i)
				is_prime[j] = false;
		}
	}
}

string S;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("1.in", "r", stdin);

	sieve();

	int TC; cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		// input string
		cin >> S;

		// count freq
		unordered_map<char, int> freq;
		for (char c : S)
			freq[c]++;

		// take prime freq
		set<char> ans;
		for (auto p : freq)
			if (is_prime[p.second])
				ans.insert(p.first);

		// output
		cout << "Case " << tc << ": ";
		for (char c : ans)
			cout << c;
		if (!ans.size()) cout << "empty";
		cout << "\n";
	}

	return 0;
}
