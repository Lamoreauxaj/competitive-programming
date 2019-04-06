#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int s, e, r;
    Interval() {}
    Interval(int ss, int ee, int rr) {
        s = ss;
        e = ee;
        r = rr;
    }
    bool operator < (const Interval& other) {
        return (e == other.e) ? s < other.s : e < other.e;
    }
};

int N;
vector<Interval> pro;
vector<long long> dp, cache;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, r; cin >> a >> b >> r;
        pro.push_back(Interval(a, b, r));
    }

    sort(pro.begin(), pro.end());
    dp.assign(N, 0);
    cache.assign(N, 0);

    for (int i = 0; i < N; i++) {
        int lo = 0, hi = i - 1;
        int prev = -1;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            if (pro[m].e >= pro[i].s) hi = m - 1;
            else prev = m, lo = m + 1;
        }
        dp[i] = pro[i].r + (prev == -1 ? 0 : cache[prev]);
        cache[i] = max(i == 0 ? 0 : cache[i - 1], dp[i]);
    }

    long long ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, dp[i]);

    cout << ans << "\n";


    return 0;
}
