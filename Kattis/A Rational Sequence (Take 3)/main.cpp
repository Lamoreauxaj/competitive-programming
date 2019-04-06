#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int TC; cin >> TC;
    while (TC--) {
        int tc; cin >> tc;

        long long N; cin >> N;
        
        long long level = floor(log(N) / log(2) + 1e-9);
        long long above = (1 << level) - 1;
        long long pos = N - above - 1;
        string dir = "";
        for (long long i = 0; i < level; i++) {
            if (pos % 2 == 0) dir += "L";
            else dir += "R";
            pos /= 2;
        }
        reverse(dir.begin(), dir.end());

        long long p = 1, q = 1;
        for (char c : dir) {
            if (c == 'L') q += p;
            else p += q;
        }

        cout << tc << " " << p << "/" << q << "\n";
    }

    return 0;
}
