#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000007;
 
int N, nums[10000], prefMax[10000];
int f[2][10001];
 
int main() {
	ios_base::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
 
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> nums[i];
 
	for (int i = 0; i < N; i++) {
		if (i == 0)
			prefMax[i] = nums[i];
		else
			prefMax[i] = max(prefMax[i - 1], nums[i]);
	}
 
	for (int i = 0; i <= N; i++)
		f[1][i] = 1;
	int ans = 1;
	for (int i = N - 1; i >= 0; i--) {
		int maxSoFar = i == 0 ? 0 : prefMax[i - 1];
		for (int j = 1; j < nums[i]; j++) {
			ans = (ans + f[1][max(maxSoFar, j)]) % MOD;
		}
		for (int j = 0; j <= i; j++) {
			f[0][j] = (int) (((long long) j * f[1][j] + f[1][j + 1]) % MOD);
		}
		for (int j = 0; j <= i + 1; j++)
			f[1][j] = f[0][j];
	}
 
	cout << ans << "\n";
 
	return 0;
}
