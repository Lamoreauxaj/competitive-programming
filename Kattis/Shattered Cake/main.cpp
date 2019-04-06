#include <bits/stdc++.h>
using namespace std;

int N, W;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> W >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int w, l; cin >> w >> l;
        sum += w * l;
    }
    cout << sum / W << "\n";

    return 0;
}
