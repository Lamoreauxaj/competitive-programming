#include "cplib.cpp"

int N, V[50000];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> V[i];
    int mx = V[N - 1];
    ll res = 0;
    for (int i = N - 2; i >= 0; i--) {
        if (mx == 1) { res = 1; break; }
        if (V[i] >= mx)
            res += V[i] - (mx - 1), mx = mx - 1;
        else
            mx = V[i];
    }
    cout << res << "\n";
}

int main() {
    cplib("main.cpp");
    testcase("3 5 2 3", "4");
    testcase("3 0 0 1", "1");
    return test();
}