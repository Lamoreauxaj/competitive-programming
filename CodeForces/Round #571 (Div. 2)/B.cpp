#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    long long ans = max(
        ((n + 1) / 2) * ((m + 1) / 3) + (m % 3 == 1 ? (n + 1) / 3 : 0),
        ((m + 1) / 2) * ((n + 1) / 3) + (n % 3 == 1 ? (m + 1) / 3 : 0));

    cout << ans << "\n";

    return 0;
}
