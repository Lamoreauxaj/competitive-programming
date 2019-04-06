#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long N;

long long modPow(long long b, long long e) {
    if (e == 0) return 1;
    long long r = modPow(b, e / 2);
    r = r * r % MOD;
    if (e % 2) r = r * b % MOD;
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;

    long long ans = 0;
    for (long long x = 1; x <= N; ) {
        long long n = N / (N / x);
        long long s = (n + x) % MOD * modPow(2, MOD - 2) % MOD;
        s = s * ((n - x + 1) % MOD) % MOD;
        ans = (ans + s * ((N / x) % MOD) % MOD) % MOD;
        x = n + 1;
    }
    cout << ans << "\n";

    return 0;
}
