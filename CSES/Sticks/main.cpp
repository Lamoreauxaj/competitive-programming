#include <bits/stdc++.h>
using namespace std;

int N, P[500010];

long long cost(long long len) {
    long long res = 0;
    for (int i = 0; i < N; i++)
        res += abs(P[i] - len);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> P[i];

    // find mean
    long long sum = 0;
    for (int i = 0; i < N; i++)
        sum += P[i];

    // find minimum ans
    int low = 1, high = 1000000000;
    while (low < high) {
        int mid = (low + high) / 2;
        int cm = cost(mid);
        int cp = cost(mid - 1), cn = cost(mid + 1);
        if (cp >= cm && cn >= cm)
            break;
        else if (cp >= cm)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // output
    cout << cost((low + high) / 2) << "\n";

    return 0;
}
