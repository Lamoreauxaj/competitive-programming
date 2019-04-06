#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);

    int TC; cin >> TC;
    while (TC--) {
        cin >> N;
        int x = 0;
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            x ^= (a % 4);
        }
        cout << (x == 0 ? "second" : "first") << "\n";
    }

    return 0;
}
