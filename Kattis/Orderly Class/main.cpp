#include <bits/stdc++.h>
using namespace std;

string A, B;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> A >> B;
    int l = A.size(), r = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[i])
            l = min(l, i), r = max(l, i);
    }

    bool works = true;
    int s = l;
    while (s <= r) {
        if (A[s] != B[r - (s - l)])
            works = false;
        s++;
    }
    if (!works) cout << "0\n";
    else {
        s = l - 1;
        int e = r + 1;
        while (s >= 0 && e < A.size() && A[s] == B[s] && A[e] == B[e] && A[s] == A[e]) s--, e++;
        cout << l - s << "\n";
    }

    return 0;
}
