#include <bits/stdc++.h>
using namespace std;

int N;
vector<double> nums[2];

int main() {
    ios_base::sync_with_stdio(false);
    freopen("1.in", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) {
        double a, b; cin >> a >> b;
        nums[0].push_back(a);
        nums[1].push_back(b);
    }

    for (int i = 0; i < 2; i++)
        sort(nums[i].begin(), nums[i].end());

    int a = N - 1, b = N - 1;
    double left = 0, right = 0, ans = 0;
    while (a >= 0 || b >= 0) {
        if (b < 0)
            left += nums[0][a] - 1, right--, a--;
        else if (a < 0)
            right += nums[1][b] - 1, left--, b--;
        else {
            if (left < right)
                left += nums[0][a] - 1, right--, a--;
            else
                right += nums[1][b] - 1, left--, b--;
        }
        ans = max(ans, min(left, right));
    }

    cout << fixed << setprecision(4) << ans << "\n";

    return 0;
}
