#include <bits/stdc++.h>
using namespace std;

long long N;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N;
    N++;

    // process each power of 2
    long long ans = 0;
    for (long long i = 0; (1LL << i) <= N; i++) {
        long long p = (1LL << (i + 1));
        long long total = (N + p - 1) / p * (1LL << i);
        long long rem = N % p;
        if (rem == 0)
            rem = p;
        total -= min(p - rem, p / 2);
        ans += total;
    }

    // output
    cout << ans << "\n";

    return 0;
}
