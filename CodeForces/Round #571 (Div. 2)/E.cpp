#include <bits/stdc++.h>
using namespace std;

long long N, M, Q, grid[1010][1010];
long long sums[1010][1010];

int find(int x, int y) {
    if (x <= N && y <= M)
        return grid[x - 1][y - 1];
    long long p = N, q = M;
    while (p * 2 < x || q * 2 < y) p *= 2, q *= 2;
    if (p < x && q < y)
        return find(x - p, y - q);
    else if (p < x)
        return 1 - find(x - p, y);
    else
        return 1 - find(x, y - q);
}

pair<int, int> togn(int x, int y) {
    int r = (x + N - 1) / N;
    int c = (y + M - 1) / M;
    return {r, c};
}

long long subSum(int x, int y) {
    if (x == 1 && y == 1) return 1;
    long long p = 1;
    while (p * 2 <= x && p * 2 <= y) p *= 2;
    if (p == 1) {
        p = 1;
        while (p * 2 < x || p * 2 < y) p *= 2;
        long long ans = (x == 1 ? y - p : x - p) - subSum(x == 1 ? 1 : x - p, y == 1 ? 1 : y - p) + (p == 1 ? 1 : (p / 2));
        return ans;
    }
    long long ans = 0;
    if (x > p && y > p)
        ans += subSum(x - p, y - p);
    ans += p / 2 * p;
    ans += p / 2 * (x - p);
    ans += p / 2 * (y - p);
    return ans;
}

long long sumRow(int y) {
    return subSum(1, y);
}

long long matSum(int x1, int y1, int x2, int y2) {
    long long ans = subSum(x2, y2);
    if (y1 > 1)
        ans -= subSum(x2, y1 - 1);
    if (x1 > 1)
        ans -= subSum(x1 - 1, y2);
    if (x1 > 1 && y1 > 1)
        ans += subSum(x1 - 1, y1 - 1);
    return ans;
}

long long totSum(long long x, long long y) {
    if (x == 0 || y == 0) return 0;
    if (x <= N && y <= M)
        return sums[x - 1][y - 1];

    if (x <= N || y <= M) {
        long long times = max(x / N, y / M);
        long long pos = sumRow(times);
        long long neg = times - pos;
        long long psum = sums[min(N, x) - 1][min(M, y) - 1];
        long long npsum = min(N, x) * min(M, y) - psum;
        long long ans = pos * psum + neg * npsum;
        if (x <= N) {
            if (sumRow(times + 1) - pos)
                ans += totSum(x, y - M * times);
            else
                ans += (y - M * times) * x - totSum(x, y - M * times);
        }
        else {
            if (sumRow(times + 1) - pos)
                ans += totSum(x - N * times, y);
            else
                ans += (x - N * times) * y - totSum(x - N * times, y);
        }
        return ans;
    }

    long long p = N, q = M;
    while (p * 2 <= x && q * 2 <= y) p *= 2, q *= 2;

    long long ans = 0;

    // add full grids
    long long times = 0;
    if (x / N < y / M) times = y / q;
    else times = x / p;
    long long pos = sumRow(times);
    long long neg = times - pos;
    long long psum = sums[N - 1][M - 1] * (p / 2 * q) + (N * M - sums[N - 1][M - 1]) * (p / 2 * q);
    ans += psum * pos + (p * q - psum) * neg;

    // add bottom right corner
    if (x / N < y / M) ans += totSum(x - p, y - q * times);
    else ans += totSum(x - p * times, y - q);

    // add sides
    if (x / N < y / M) {
        ans += sums[N - 1][(y - q * times) - 1];
        psum = sums[(x - p) - 1][M - 1];
        ans += neg * psum + ((x - p) * M - psum) * pos;
    }
    else {
        ans += sums[(x - p * times) - 1][M - 1];
        psum = sums[N - 1][(y - q) - 1];
        ans += neg * psum + ((y - q) * N - psum) * pos;
    }
    return ans;
}

long long newSum(long long x, long long y) {
    long long rows = x / N;
    long long prowsum = totSum(N, y);
    long long nprowsum = N * y - prowsum;
    long long pos = 0;
    if (rows)
        pos = sumRow(rows);
    long long neg = rows - pos;
    long long ans = prowsum * pos + nprowsum * neg;
    if (x - rows * N) {
        if (sumRow(rows + 1) - pos)
            ans += totSum(x - rows * N, y);
        else
            ans += (x - rows * N) * y - totSum(x - rows * N, y);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    // input
    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++) {
        string tmp; cin >> tmp;
        for (int j = 0; j < M; j++)
            grid[i][j] = tmp[j] - '0';
    }

    // calculate submatrix sums
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) sums[i][j] = grid[i][j];
            else if (i == 0) sums[i][j] = grid[i][j] + sums[i][j - 1];
            else if (j == 0) sums[i][j] = grid[i][j] + sums[i - 1][j];
            else sums[i][j] = grid[i][j] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
        }
    }

    /*
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            long long sum = 0;
            for (int a = 0; a <= i; a++) {
                for (int b = 0; b <= j; b++) {
                    sum += find(a + 1, b + 1);
                }
            }
            if (sum != newSum(i + 1, j + 1)) {
                throw runtime_error("Foo!");
            }
        }
    }
    */

    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        long long ans = newSum(x2, y2);
        if (x1 > 1) ans -= newSum(x1 - 1, y2);
        if (y1 > 1) ans -= newSum(x2, y1 - 1);
        if (x1 > 1 && y1 > 1) ans += newSum(x1 - 1, y1 - 1);
        cout << ans << "\n";
    }

    return 0;
}
