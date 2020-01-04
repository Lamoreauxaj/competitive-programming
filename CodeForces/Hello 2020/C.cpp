#include <bits/stdc++.h>
using namespace std;

int N, MOD;
long long fact[250010];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> MOD;

    fact[0] = 1 % MOD;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    long long res = 0;
    for (int k = 1; k <= N; k++) {
        long long term = (long long) (N - k + 1) * (N - k + 1) % MOD;
        term = term * fact[N - k] % MOD;
        term = term * fact[k] % MOD;
        res = (res + term) % MOD;
    }

    cout << res << "\n";

    return 0;
}
