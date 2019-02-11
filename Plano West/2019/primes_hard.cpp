#include <bits/stdc++.h>
using namespace std;

// sieve for primes up to lim
vector<int> primes;
vector<bool> is_prime;
void sieve(int lim) {
    primes.push_back(2);
    is_prime.assign(lim, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 4; i < lim; i += 2)
        is_prime[i] = false;
    for (int i = 3; i < lim; i += 2) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = (long long) i * i; j < lim; j += i)
                is_prime[j] = false;
        }
    }
}

// return prime factors of N
vector<int> prime_factors(int N) {
    vector<int> fact;
    for (int i = 0; i < primes.size() && (long long) primes[i] * primes[i] <= N; i++) {
        while (N % primes[i] == 0) {
            fact.push_back(primes[i]);
            N /= primes[i];
        }
    }
    if (N != 1)
        fact.push_back(N);
    return fact;
}

long long N;
string line;
vector<int> factors;
multiset<int> pfactors;

int main() {
    
    // sieve
    sieve(1000001);
    
    int TC; cin >> TC;
    while (TC--) {
        // input
        factors.clear();
        pfactors.clear();
        cin >> N;
        getline(cin, line);
        stringstream ss(line);
        string tmp;
        while (ss >> tmp) {
            int k; ss >> k;
            factors.push_back(k);
        }
        
        // check each factor
        bool good = true;
        set<int> wrongs; // store wrong factors
        for (int i : factors) {
            if (!is_prime[i]) {
                good = false;
                wrongs.insert(i);
                vector<int> curr = prime_factors(i);
                for (int j : curr)
                    pfactors.insert(j);
            }
            else {
                pfactors.insert(i);
            }
        }
        
        // output correct or wrong
        if (good)
            cout << "correct!\n";
        else
            cout << "WRONG!\n";
        
        // output wrong numbers in the factorization
        for (int w : wrongs)
            cout << w << " is not a prime number.\n";
        
        // output the correct factorization
        cout << N << " = ";
        bool first = true;
        for (int i : pfactors) {
            if (!first)
                cout << " x ";
            first = false;
            cout << i;
        }
        cout << "\n";
    }
    
    return 0;
}
