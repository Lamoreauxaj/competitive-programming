#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    
    // input
    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    // precalculate costs
    vector<int> val(N - 1);
    for (int i = 1; i < N; i++)
        val[i - 1] = -abs(A[i] - A[i - 1]) + 1;
    
    // find largest sum of contiguous sub array (max 1D range sum)
    int ans = 0, sum = 0;
    for (int i = 0; i < N - 1; i++) {
        sum += val[i];
        if (sum < 0)
            sum = 0;
        ans = max(ans, sum);
    }
    
    // output + 1 for extra length
    cout << ans + 1 << "\n";
    
    return 0;
}
