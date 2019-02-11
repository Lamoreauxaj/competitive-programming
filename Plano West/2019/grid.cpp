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

// return number of divisors of N
long long div_count(int N) {
    long long ans = 1;
    for (int i = 0; i < primes.size() && (long long) primes[i] * primes[i] <= N; i++) {
        if (N % primes[i] == 0) {
            int exp = 0;
            while (N % primes[i] == 0)
                exp++,
                N /= primes[i];
            ans *= (exp + 1);
        }
    }
    if (N != 1)
        ans *= 2;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    // sieve
    sieve(100000);
    
    // precalculate the sum of each prefix of div counts
    vector<int> sum(100001);
    for (int i = 1; i <= 100000; i++) {
        sum[i] = sum[i - 1] + div_count(i);
    }
    
    int TC; cin >> TC;
    while (TC--) {
        // input
        int N; cin >> N;
        
        // output
        cout << sum[N] << "\n";
    }
    
    return 0;
}
