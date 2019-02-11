#include <bits/stdc++.h>
using namespace std;

// sieve for primes up to lim
vector<int> primes;
void sieve(int lim) {
    vector<bool> is_prime(lim, true);
    primes.push_back(2);
    for (int i = 3; i < lim; i += 2) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = (long long) i * i; j < lim; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    
    // sieve
    sieve(100000);
    
    // precalculate next primes
    unordered_map<int, int> next;
    for (int i = primes.size() - 1; i >= 0; i--)
        next[primes[i]] = primes[i + 1];
    
    int TC; cin >> TC;
    while (TC--) {
        // input
        int N; cin >> N;
        
        // output
        cout << next[N] << "\n";
    }
    
    return 0;
}
