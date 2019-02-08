#include <bits/stdc++.h>
using namespace std;

int M, N, T;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("test.in", "r", stdin);

    while (cin >> M >> N >> T) {

        // try all amounts of burgers
        int maxB = 0, beer = 1000000;
        for (int i = 0; i * M <= T; i++) {
            int j = (T - i * M) / N;
            if (T - i * M - j * N < beer) {
                maxB = i + j;
                beer = T - i * M - j * N;
            } else if (i + j > maxB && T - i * M - j * N == beer) {
                maxB = i + j;
            }
        }

        // output
        cout << maxB;
        if (beer)
            cout << " " << beer;
        cout << "\n";
    }

    return 0;
}
