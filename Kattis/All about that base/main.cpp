#include <bits/stdc++.h>
using namespace std;

string X, Y, Z, op;

int val(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'a' + 10;
}

int parse(string n, int b) {
    long long max = (1LL << 32) - 1;
    long long v = 0;
    for (int i = 0; i < n.size(); i++) {
        if (b == 1) {
            if (n[i] != '1') return -1;
            v = v + 1;
            continue;
        }
        if (val(n[i]) >= b) return -1;
        v = v * b + val(n[i]);
        if (v > max) return -1;
    }
    if (v < 1) return -1;
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    int TC; cin >> TC;
    while (TC--) {

        string tmp;
        cin >> X >> op >> Y >> tmp >> Z;

        bool found = false;
        for (int i = 1; i <= 36; i++) {
            int x = parse(X, i);
            int y = parse(Y, i);
            int z = parse(Z, i);
            if (x == -1 || y == -1 || z == -1) continue;
            bool works = false;
            if (op == "*") {
                if (z % y == 0 && z / y == x) works = true;
            }
            else if (op == "/") {
                if (x % y == 0 && x / y == z) works = true;
            }
            else if (op == "+") {
                if ((long long) x + y == z) works = true;
            }
            else if (op == "-") {
                if ((long long) x - y == z) works = true;
            }
            found |= works;
            if (works) {
                if (i == 36) cout << "0";
                else if (i < 10) cout << i;
                else cout << (char)(i + 'a' - 10);
            }
        }

        if (!found) cout << "invalid";
        cout << "\n";

    }

    return 0;
}
