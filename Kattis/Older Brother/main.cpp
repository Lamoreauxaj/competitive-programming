#include <bits/stdc++.h>
using namespace std;

int Q;
vector<int> primes;
void sieve(int lim) {
    vector<bool> isPrime(lim, true);
    primes.push_back(2);
    for (int i = 3; i < lim; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = (long long) i * i; j < lim; j += i) isPrime[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> Q;

    sieve(1000000);

    int found = 0;
    for (int i = 0; i < primes.size() && (long long) primes[i] * primes[i] <= Q && found < 2; i++) {
        int e = 0;
        while (Q % primes[i] == 0)
            Q /= primes[i], e++;
        if (e) found++;
    }
    if (Q != 1) found++;

    if (found == 1) cout << "yes\n"; else cout << "no\n";

    return 0;
}
