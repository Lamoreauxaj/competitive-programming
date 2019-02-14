#include <bits/stdc++.h>
using namespace std;

string S;
int lps[1000010];

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    // input
    cin >> S;

    // calculate lps
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < S.size()) {
        if (S[i] == S[len])
            lps[i++] = ++len;
        else {
            if (len)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }

    // output
    cout << S.substr(0, lps[S.size() - 1]) << "\n";

    return 0;
}
