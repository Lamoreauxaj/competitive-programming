#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
vector<long long> pref;

long long sum(int l, int r) {
    if (l) return pref[r] - pref[l - 1];
    return pref[r];
}

vector<vector<long long>> memo(5000, vector<long long>(5000, -1));
long long dp(int l, int r) {
    if (l > r) return 0;
    if (memo[l][r] != -1) return memo[l][r];
    long long ans = max(sum(l, r) - dp(l + 1, r), sum(l, r) - dp(l, r - 1));
    return memo[l][r] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    pref.assign(N, 0);
    pref[0] = A[0];
    for (int i = 1; i < N; i++)
        pref[i] = pref[i - 1] + A[i];
    
    cout << dp(0, N - 1) << "\n";

    return 0;
}
