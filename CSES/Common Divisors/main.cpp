#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<int, int> nums;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        nums[a]++;
    }

    for (int j = 1000000; j >= 1; j--) {
        int cnt = 0;
        for (int k = j; k <= 1000000 && cnt < 2; k += j)
            if (nums.count(k)) cnt += nums[k];
        if (cnt >= 2) {
            cout << j << "\n";
            break;
        }
    }

    return 0;
}
