#include <bits/stdc++.h>
using namespace std;

int N;

// return quartic calculated from system of equations
long long count_ways(long long n) {
    return n * n * n * n / 2 - 9 * n * n / 2 + 12 * n - 8;
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N;

    // output each k
    for (int k = 1; k <= N; k++) {
        cout << count_ways(k) << "\n";
    }

    return 0;
}
