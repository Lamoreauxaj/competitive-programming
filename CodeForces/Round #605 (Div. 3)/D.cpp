#include "cplib.cpp"

int N, A[200010], desc[200010], inc[200010];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    desc[0] = 1;
    for (int i = 1; i < N; i++) {
        desc[i] = 1;
        if (A[i] > A[i - 1]) desc[i] += desc[i - 1];
    }
    inc[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--) {
        inc[i] = 1;
        if (A[i] < A[i + 1]) inc[i] += inc[i + 1];
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0 && i < N - 1) {
            int l = desc[i - 1], r = inc[i + 1];
            if (A[i - 1] < A[i + 1])
                res = max(res, l + r);
        }
        res = max(res, desc[i]);
    }
    cout << res << "\n";
}

int main() {
    cplib("D.cpp");
    testcase("5 1 2 5 3 4", "4");
    testcase("2 1 2", "2");
    testcase("7 6 5 4 3 2 4 3", "2");
    return test();
}