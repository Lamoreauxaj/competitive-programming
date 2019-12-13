#include "cplib.cpp"

int N, X[1000010], Y[1000010];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];
    sort(X, X + N);
    sort(Y, Y + N);
    ll res = 0;
    for (int j = 0; j < N; j++) {
        res += abs(X[j] - (j + 1));
        res += abs(Y[j] - (j + 1));
    }
    cout << res << "\n";
}

int main() {
    cplib("main.cpp");
    testcase("3 1 3 2 3 3 1", "1");
    testcase("4 1 4 4 1 1 1 4 4", "4");
    return test();
}