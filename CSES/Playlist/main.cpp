#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<int, int> last;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N;

    // find longest sequence
    int ans = 0, len = 0;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (last.count(a))
            len = min(len + 1, i - last[a]);
        else
            len++;
        last[a] = i;
        ans = max(ans, len);
    }

    // output
    cout << ans << "\n";

    return 0;
}
