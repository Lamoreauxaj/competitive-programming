#include <bits/stdc++.h>
using namespace std;

string A, B;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> A >> B;

    pair<int, int> bcnt(0, 0);
    for (int i = 0; i < B.size(); i++)
        (B[i] == '1' ? bcnt.second : bcnt.first)++;
    pair<int, int> cnt(0, 0);
    for (int i = 0; i < B.size(); i++)
        (A[i] == '1' ? cnt.second : cnt.first)++;
    int ans = 0;
    for (int i = 0; i < A.size() - B.size() + 1; i++) {
        int diff = abs(cnt.first - bcnt.first);
        if (diff % 2 == 0) {
            ans++;
        }
        if (i < A.size() - B.size())
            (A[i] == '1' ? cnt.second : cnt.first)--,
            (A[i + B.size()] == '1' ? cnt.second : cnt.first)++;
    }
    cout << ans << "\n";

    return 0;
}
