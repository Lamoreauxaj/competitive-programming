#include <bits/stdc++.h>
using namespace std;

int N;
long long M;
vector<long long> nums;
vector<long long> half;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    cin >> N >> M;
    nums.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    for (int i = 0; i < (1 << (N / 2)); i++) {
        long long sum = 0;
        for (int j = 0; j < N / 2; j++)
            if (i & (1 << j))
                sum += nums[j];
        half.push_back(sum);
    }
    sort(half.begin(), half.end());

    long long res = 0;
    for (int i = 0; i < (1 << (N - N / 2)); i++) {
        long long sum = 0;
        for (int j = N / 2; j < N; j++)
            if (i & (1 << (j - N / 2)))
                sum += nums[j];

        int lo = 0, hi = half.size() - 1, ans = -1;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            if (half[m] > M - sum)
                hi = m - 1;
            else
                lo = m + 1, ans = m;
        }

        res += ans + 1;
    }

    cout << res << "\n";

    return 0;
}
