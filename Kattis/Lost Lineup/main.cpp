#include <bits/stdc++.h>
using namespace std;

int N, D[101], res[101];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N - 1; i++) cin >> D[i];

    res[0] = 1;
    for (int i = 0; i < N - 1; i++)
        res[D[i] + 1] = i + 2;

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";

    return 0;
}
