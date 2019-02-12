#include <bits/stdc++.h>
using namespace std;

int N, X;
multiset<int> children;

int main() {
    ios_base::sync_with_stdio(false);
    
    // input
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        children.insert(a);
    }

    // greedily assign children
    int ans = 0;
    while (children.size()) {
        auto large_it = --children.end();
        int val = *large_it;
        children.erase(large_it);
        auto it = children.upper_bound(X - val);
        if (it != children.begin())
            children.erase(--it);
        ans++;
    }

    // output
    cout << ans << "\n";

    return 0;
}
