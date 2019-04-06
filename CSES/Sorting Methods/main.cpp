#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A, B, C, D;

long long countInversions(int l, int r) {
    if (l >= r) return 0;
    long long inv = 0;
    vector<int> tempL, tempR;
    int m = (l + r) / 2;
    inv += countInversions(l, m);
    inv += countInversions(m + 1, r);
    for (int j = l; j <= m; j++) tempL.push_back(A[j]);
    for (int j = m + 1; j <= r; j++) tempR.push_back(A[j]);
    int i = 0, j = 0, p = l;
    while (i < tempL.size() && j < tempR.size()) {
        if (tempL[i] <= tempR[j])
            A[p++] = tempL[i++];
        else
            inv += tempL.size() - i, A[p++] = tempR[j++];
    }
    while (i < tempL.size())
        A[p++] = tempL[i++];
    while (j < tempR.size())
        A[p++] = tempR[j++];
    return inv;
}

int lis() {
    vector<int> l(N, 1);
    vector<int> d(N + 1, 1000000);
    d[0] = 0;
    for (int j = 0; j < N; j++) {
        int lo = 0, hi = N, prev = 0;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            if (d[m] <= B[j])
                prev = m, lo = m + 1;
            else
                hi = m - 1;
        }
        l[j] = prev + 1;
        d[l[j]] = min(d[l[j]], B[j]);
    }
    return *max_element(l.begin(), l.end());
}

int prefix() {
    int p = N;
    for (int j = N - 1; j >= 0; j--) {
        if (C[j] == p) {
            p--;
        }
    }
    return N - p;
}

int swaps() {
    vector<pair<int, int>> E;
    for (int i = 0; i < N; i++) E.push_back({D[i], i});
    sort(E.begin(), E.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (E[i].second == i) continue;
        swap(E[i], E[E[i].second]);
        i--;
        ans++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];
    B = C = D = A;

    cout << countInversions(0, N - 1) << " ";
    cout << swaps() << " ";
    cout << N - lis() << " ";
    cout << N - prefix() << "\n";

    return 0;
}
