#include <bits/stdc++.h>
using namespace std;

long long countDig(long long n, int d) {
    string s = to_string(n);
    long long res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        res += stoll(i == 0 ? "0" : s.substr(0, i)) * ((long long) pow(10, s.size() - i - 1));
        if (s[i] - '0' == d)
            res += stoll(i == s.size() - 1 ? "0" : s.substr(i + 1)) + 1;
        else if (s[i] - '0' > d)
            res += (long long) pow(10, s.size() - i - 1);
    }
    return res;
}

long long N;

bool check(long long n) {
    return countDig(n, 1) <= N;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;

    long long lo = 1, hi = 1;
    while (countDig(hi, 1) <= N)
        hi *= 2;

    long long ans = 0;
    while (lo <= hi) {
        long long m = (lo + hi) / 2;
        if (check(m)) lo = m + 1, ans = m;
        else hi = m - 1;
    }

    cout << ans << "\n";

    return 0;
}
