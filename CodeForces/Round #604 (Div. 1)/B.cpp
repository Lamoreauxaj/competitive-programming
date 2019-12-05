#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;
const int MOD = 1000000007;
const ld EPS = 1e-9;
const ld PI = acos(-1);

#define x first
#define y second

int A, B, C, D;

bool works() {
    int a = A, b = B, c = C, d = D;

    if (a == 0) {
        c -= d - 1;
        if (c < 0) return false;
        return c == b || c == b + 1 || c == b + 2;
    }

    b -= a;
    if (b < 0) return false;
    c -= d;
    if (c < 0) return false;
    return abs(b - c) <= 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(10);

    cin >> A >> B >> C >> D;

    bool swapped = false;
    if (D == 0) {
        swap(A, D), swap(B, C);
        swapped = true;
    }
    
    if (A == 0) {
        if (works()) {
            cout << "YES\n";
            vector<int> res;
            int rc = C - D + 1;
            if (rc == B + 2)
                res.push_back(2);
            for (int i = 0; i < B; i++)
                res.push_back(1), res.push_back(2);
            for (int i = 0; i < D; i++) {
                if (i) res.push_back(2);
                res.push_back(3);
            }
            if (rc >= B + 1)
                res.push_back(2);
            assert(res.size() == A + B + C + D);
            for (int i = 0; i < res.size(); i++) {
                if (i) cout << " ";
                if (swapped) cout << 3 - res[i];
                else cout << res[i];
            }
            cout << "\n";
        }
        else cout << "NO\n";
        return 0;
    }

    if (works()) {
        cout << "YES\n";
        vector<int> res;
        int rb = B - A, rc = C - D;
        if (rb > rc) res.push_back(1);
        for (int i = 0; i < A; i++)
            res.push_back(0), res.push_back(1);
        for (int i = 0; i < min(rb, rc); i++)
            res.push_back(2), res.push_back(1);
        for (int i = 0; i < D; i++)
            res.push_back(2), res.push_back(3);
        if (rc > rb) res.push_back(2);
        assert(res.size() == A + B + C + D);
        for (int i = 0; i < res.size(); i++) {
            if (i) cout << " ";
            cout << res[i];
        }
        cout << "\n";
    }
    else cout << "NO\n";

    return 0;
}
