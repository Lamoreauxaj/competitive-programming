#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N;

    // add towers to set
    multiset<int> open;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int s; cin >> s;
        auto it = open.upper_bound(s);
        if (it == open.end())
            ans++, open.insert(s);
        else {
            open.erase(it);
            open.insert(s);
        }
    }

    // output
    cout << ans << "\n";

    return 0;
}
