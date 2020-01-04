#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<string> A, B;
vector<string> res;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string t; cin >> t;
        A.push_back(t);
    }
    for (int i = 0; i < M; i++) {
        string t; cin >> t;
        B.push_back(t);
    }

    int a = 0, b = 0;
    do {
        res.push_back(A[a] + B[b]);
        a = (a + 1) % N;
        b = (b + 1) % M;
    } while (a != 0 || b != 0);

    cin >> Q;
    while (Q--) {
        int y; cin >> y;
        y--;
        cout << res[y % res.size()] << "\n";
    }

    return 0;
}
