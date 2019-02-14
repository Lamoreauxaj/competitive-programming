#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> S;
    unordered_set<char> seen;
    for (int i = 0; i < S.size(); i++) {
        seen.insert(S[i]);
        if (seen.size() == 4) {
            cout << S[i];
            seen.clear();
        }
    }
    string to = "AGCT";
    for (char c : to) {
        if (!seen.count(c)) {
            cout << c << "\n";
            break;
        }
    }

    return 0;
}
