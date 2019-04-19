#include <bits/stdc++.h>
using namespace std;

set<int> sol;
void rec(int last, int tot, int n) {
    sol.insert(tot + n - 1);
    for (int i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        if (i <= last)
            rec(i, tot + i - 1, n / i);
        if (n / i <= last)
            rec(n / i, tot + n / i - 1, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("4.in", "r", stdin);

    int N; cin >> N;

    rec(N, 0, N);

    cout << sol.size() << "\n";
    bool first = true;
    for (int i : sol) {
        if (!first) cout << " ";
        first = false;
        cout << i;
    }
    cout << "\n";

    return 0;
}
