#include <bits/stdc++.h>
using namespace std;

string S;
vector<char> T;
vector<int> P;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> S;

    // set up for even palindromes
    T.assign(S.size() * 2 + 1, ' ');
    P.assign(T.size(), 0);
    for (int i = 0; i < S.size(); i++)
        T[i * 2 + 1] = S[i];

    // run Manacher's algorithm
    int C = 0, R = 0;
    for (int i = 0; i < T.size(); i++) {
        int mirr = 2 * C - i;
        if (i < R)
            P[i] = min(R - i, P[mirr]);

        while (i + 1 + P[i] < T.size() && i - 1 - P[i] >= 0 && T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // find maximum palindrome
    int len = 0, index = 0;
    for (int i = 0; i < T.size(); i++) {
        if (P[i] > len) {
            len = P[i];
            index = (i + 1) / 2;
        }
    }

    // output
    cout << S.substr(index - (len + 1) / 2, len) << "\n";

    return 0;
}
