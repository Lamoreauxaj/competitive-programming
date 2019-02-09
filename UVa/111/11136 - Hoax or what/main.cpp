#include <bits/stdc++.h>
using namespace std;

int N;
multiset<int> urn;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("test.in", "r", stdin);

    while (cin >> N, N) {
        // process days
        urn.clear();
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            int k; cin >> k;
            for (int j = 0; j < k; j++) {
                int a; cin >> a;
                urn.insert(a);
            }

            // pull from the end of the day
            int small = *urn.begin();
            int large = *(--urn.end());
            urn.erase(urn.begin());
            urn.erase(--urn.end());

            // add to sum
            sum += large - small;
        }

        // output
        cout << sum << "\n";
    }

    return 0;
}
