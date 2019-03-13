#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int N, R;
vector<int> fact;

pair<int, pair<int, int>> egcd(int a, int b) {
    if (a == 0) {
        return {b, {0, 1}};
    }
    auto r = egcd(b % a, a);
    return {r.first, {r.second.second - b / a * r.second.first, r.second.first}};
}

int modInverse(int a) {
    return (egcd(a, MOD).second.first % MOD + MOD) % MOD;
}

int choose(int n, int r) {
    long long res = fact[n];
    res = res * modInverse(fact[r]) % MOD;
    res = res * modInverse(fact[n - r]) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    fact.assign(1000010, 1);
    for (int i = 1; i < fact.size(); i++)
        fact[i] = (long long) fact[i - 1] * i % MOD;

    int TC; cin >> TC;
    while (TC--) {
        cin >> N >> R;

        cout << choose(N, R) << "\n";
    }

    return 0;
}
