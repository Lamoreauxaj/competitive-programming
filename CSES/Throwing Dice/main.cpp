#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
typedef vector<vector<int>> Mat;

Mat mat = {{0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1}};

Mat multiply(Mat& A, Mat& B) {
    Mat res(A.size(), vector<int>(B[0].size(), 0));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < A[0].size(); k++) {
                res[i][j] += (long long) A[i][k] * B[k][j] % MOD;
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

vector<Mat> powers;

long long N;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    
    powers.push_back(mat);
    for (int i = 0; i < 60; i++)
        powers.push_back(multiply(powers.back(), powers.back()));

    Mat base = {{0}, {0}, {0}, {0}, {0}, {1}};

    while (N) {
        long long j;
        for (j = 0; !(N & (1LL << j)); j++);
        base = multiply(powers[j], base);
        N -= (1LL << j);
    }

    cout << base[5][0] << "\n";

    return 0;
}
