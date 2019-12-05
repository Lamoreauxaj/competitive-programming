#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;
const int MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1);

#define x first
#define y second

int modpow(int b, int e) {
    if (e == 0) return 1;
    ll r = modpow(b, e / 2);
    r = r * r % MOD;
    if (e % 2 != 0) r = r * b % MOD;
    return (int) r;
}

int modinv(int a) {
    return modpow(a, MOD - 2);
}

ll mod(ll a) {
    return (a % MOD + MOD) % MOD;
}

int HUNDINV;

int N, Q;
ll P[200010];
ll invOf[101];
ll pinv[200010];
set<int> chp;
ll pref1[200010]; // store (1 - p1) + p1 * (1 - p2) + p1 * p2 * (1 - p3) + ...
ll pref2[200010]; // store p1 * p2 * p3 * ...
ll pref2inv[200010];
ll pref3[200010]; // store (1 - p1) + p1 * (1 - p2) * 2 + p1 * p2 * (1 - p3) * 3 + ...

ll range1(int a, int b) {
    ll res = mod(pref1[b] - pref1[a - 1]);
    res = res * pref2inv[a - 1] % MOD;
    return res;
}

ll range3(int a, int b) {
    ll res = mod(pref3[b] - pref3[a - 1]);
    res = res * pref2inv[a - 1] % MOD;
    res = mod(res - (a - 1) * range1(a, b) % MOD);
    return res;
}

ll expect(int a, int b) {
    ll den = mod(1 - range1(a, b));
    ll rhs = pref2[b] * pref2inv[a - 1] % MOD * (b - a + 1) % MOD;
    ll num = (range3(a, b) + rhs) % MOD;
    return num * modinv(den) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(10);

    for (int i = 1; i <= 100; i++)
        invOf[i] = modinv(i);

    HUNDINV = invOf[100];
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        pinv[i] = invOf[P[i]] * 100 % MOD;
        P[i] = HUNDINV * P[i] % MOD;
    }

    chp.insert(1);

    pref1[0] = 0;
    pref2[0] = 1;
    pref3[0] = 0;
    pref2inv[0] = 1;

    for (int i = 1; i <= N; i++) {
        pref2[i] = pref2[i - 1] * P[i] % MOD;
    }

    for (int i = 1; i <= N; i++) {
        pref2inv[i] = pref2inv[i - 1] * pinv[i] % MOD;
    }

    for (int i = 1; i <= N; i++) {
        pref1[i] = (pref1[i - 1] + pref2[i - 1] * (((1 - P[i]) % MOD + MOD) % MOD)) % MOD;
    }

    for (int i = 1; i <= N; i++) {
        pref3[i] = (pref3[i - 1] + pref2[i - 1] * i % MOD * (((1 - P[i]) % MOD + MOD) % MOD)) % MOD;
    }

    /*
    cout << "range1: ";
    cout << range1(1, 2) * 4 % MOD << "\n";
    cout << pref3[2] * 2 % MOD << "\n";
    cout << "range3: ";
    cout << range3(1, 2) * 2 % MOD << "\n";
    */

    ll res = expect(1, N);
    // cout << res << "\n";
    for (int i = 0; i < Q; i++) {
        int u; cin >> u;

        if (chp.count(u)) {
            chp.erase(u);
            int nxt, prv;
            auto nxtit = chp.upper_bound(u);

            if (nxtit == chp.end()) nxt = N + 1;
            else nxt = *nxtit;
            nxtit--;
            prv = *nxtit;

            
            res = mod(res - expect(prv, u - 1));
            res = mod(res - expect(u, nxt - 1));
            res = mod(res + expect(prv, nxt - 1));
        }
        else {
            int nxt, prv;
            auto nxtit = chp.upper_bound(u);

            if (nxtit == chp.end()) nxt = N + 1;
            else nxt = *nxtit;
            nxtit--;
            prv = *nxtit;
            chp.insert(u);

            res = mod(res - expect(prv, nxt - 1));
            res = mod(res + expect(prv, u - 1));
            res = mod(res + expect(u, nxt - 1));
        }

        cout << res << "\n";

    }

    return 0;
}
