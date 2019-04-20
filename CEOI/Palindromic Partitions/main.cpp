#include <bits/stdc++.h>
using namespace std;

const int P = 1009;
const int MOD = 1e9 + 7;

int modpow(int b, int e) {
    if (e == 0)
        return 1;
    long long r = modpow(b, e / 2);
    r = r * r % MOD;
    if (e % 2 == 1)
        r = r * b % MOD;
    return (int) r;
}

int solve(string word) {
    int s = 0, e = word.size() - 1;
    int i = 0, j = word.size() - 1;
    long long lhash = 0, rhash = 0;
    int ans = 0;
    while (true) {
        if (i != s && lhash == rhash && word.substr(s, i - 1 - s) == word.substr(j + 1, e - j - 1)) {
            s = i;
            e = j;
            lhash = 0;
            rhash = 0;
            ans += 2;
            continue;
        }
        if (i >= j) break;
        lhash = (lhash * P + (word[i] - 'a')) % MOD;
        i++;
        rhash = (rhash + (word[j] - 'a') * (long long) modpow(P, e - j)) % MOD;
        j--;
    }
    if (s <= e)
        ans++;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("1.in", "r", stdin);

    int TC; cin >> TC;
    while (TC--) {
        string word;
        cin >> word;

        cout << solve(word) << "\n";
    }

    return 0;
}
