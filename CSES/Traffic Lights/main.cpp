#include <bits/stdc++.h>
using namespace std;

int X, N;
set<int> pos;
map<int, int> sizes;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> X >> N;
    pos.insert(0); pos.insert(X);
    sizes[X]++;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        auto aft = pos.upper_bound(a);
        auto bef = aft; bef--;
        int l = *aft - *bef;
        pos.insert(a);
        sizes[l]--;
        if (!sizes[l]) sizes.erase(l);
        sizes[a - *bef]++; sizes[*aft - a]++;

        if (i) cout << " ";
        cout << (*(--sizes.end())).first;
    }
    cout << "\n";

    return 0;
}
