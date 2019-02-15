#include <bits/stdc++.h>
using namespace std;

int N, K, A[500010];

int count_subarrays(long long sum) {
    long long curr = 0; int res = 0;
    for (int i = 0; i < N; i++) {
        if (curr + A[i] > sum)
            curr = 0, res++;
        if (curr + A[i] > sum)
            return 1000000;
        curr += A[i];
    }
    return res + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    long long low = 0, high = 1000000000LL * (N + 1);
    long long ans = 0;
    while (low < high) {
        long long mid = (low + high) / 2;
        int cp = count_subarrays(mid - 1), c = count_subarrays(mid), cn = count_subarrays(mid + 1);
        if (c <= K && cp > K) {
            ans = mid;
            break;
        }
        if (cn <= K && c > K) {
            ans = mid + 1;
            break;
        }
        if (c > K)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << ans << "\n";

    return 0;
}
