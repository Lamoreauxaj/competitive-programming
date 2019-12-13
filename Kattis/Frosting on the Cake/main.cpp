#include "cplib.cpp"

int N, A[100010], B[100010];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    ll cnt[3] = {0, 0, 0};
    for (int i = 0; i < N; i++) cnt[i % 3] += B[i];
    ll res[3] = {0, 0, 0};
    for (int j = 0; j < N; j++)
        res[j % 3] += cnt[0] * A[j], res[(j + 1) % 3] += cnt[1] * A[j], res[(j + 2) % 3] += cnt[2] * A[j];
    cout << res[1] << " " << res[2] << " " << res[0] << "\n";
}

int main() {
    cplib("main.cpp");
    testcase("3 1 1 1 1 1 1", "3 3 3");
    testcase("7 6 2 4 5 1 1 4 2 5 1 4 2 3 4", "155 131 197");
    return test();
}