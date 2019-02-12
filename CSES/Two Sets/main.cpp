#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> N;

    // calculate sum
    long long sum = (long long) N * (N + 1) / 2;

    // output no if not possible
    if (sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    vector<int> set1, set2;

    // case where n is a multiple of 4
    if (N % 4 == 0)
        for (int i = 4; i <= N; i += 4)
            set1.push_back(i - 3), set1.push_back(i),
            set2.push_back(i - 2), set2.push_back(i - 1);

    // case where n is one less than a multiple of 4
    if (N % 4 == 3) {
        set1.push_back(1); set1.push_back(N - 1);
        set2.push_back(N);
        for (int i = 5; i <= N; i += 4)
            set1.push_back(i - 3), set1.push_back(i),
            set2.push_back(i - 2), set2.push_back(i - 1);
    }

    // output
    cout << "YES\n";
    cout << set1.size() << "\n";
    for (int i = 0; i < set1.size(); i++) {
        if (i) cout << " ";
        cout << set1[i];
    }
    cout << "\n";
    cout << set2.size() << "\n";
    for (int i = 0; i < set2.size(); i++) {
        if (i) cout << " ";
        cout << set2[i];
    }
    cout << "\n";

    return 0;
}
