#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    long long N, b;
    cin >> N >> b;
    long long tot = 1;
    for (int i = 0; i < b + 1; i++)
        tot *= 2;
    tot -= 1;
    if (N <= tot) cout << "yes\n";
    else cout << "no\n";

    return 0;
}
