#include <bits/stdc++.h>
using namespace std;

int N, M, K, B[200010];
multiset<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        A.insert(a);
    }
    for (int i = 0; i < M; i++)
        cin >> B[i];

    // sort the lists and insert applicants into set
    sort(B, B + M);

    // assign apartments greedily
    int ans = 0;
    for (int i = 0; i < M; i++) {
        auto it = A.lower_bound(B[i] - K);
        if (it == A.end()) continue;
        if (*it > B[i] + K)
            continue;
        ans++;
        A.erase(it);
    }

    // output
    cout << ans << "\n";


    return 0;
}
