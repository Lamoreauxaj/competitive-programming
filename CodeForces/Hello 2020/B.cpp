#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    long long res = 0, as = 0;
    vector<pair<int, bool>> vals;
    for (int i = 0; i < N; i++) {
        int L; cin >> L;
        int mn, mx;
        cin >> mn;
        mx = mn;
        bool asc = false;
        for (int i = 1; i < L; i++) {
            int a; cin >> a;
            if (a > mn) asc = true;
            mn = min(mn, a);
            mx = max(mx, a);
        }
        if (asc) as++;
        else {
            vals.push_back({mn, true});
            vals.push_back({mx, false});
        }
    }
    // cout << res << "\n";
    
    res += as * as;
    res += as * (N - as) * 2;

    sort(vals.begin(), vals.end());

    int cnt = 0;
    for (auto p : vals) {
        // cout << p.first << " " << p.second << "\n";
        if (p.second) cnt++;
        else {
            res += cnt;
        }
    }

    cout << res << "\n";

    return 0;
}
