#include "contest/template.cpp"

int N, Q;
vi X;
vvi mn;

void solve() {
    re(N, Q);
    X.rsz(N);
    re(X);
    mn.asn(N, vi(25));
    rep(i, N) {
        mn[i][0] = X[i];
        repr(k, 1, 25) {
            mn[i][k] = mn[i][k-1];
            if (i-(1<<(k-1)) >= 0)
                ckmin(mn[i][k], mn[i-(1<<(k-1))][k-1]);
        }
    }
    dbg(mn);
    rep(q, Q) {
        int a, b, res=MOD;
        re(a, b); a-=2, b--;
        repr(k, 24, -1) {
            if ((b-a) >= (1<<k))
                ckmin(res, mn[b][k]),
                b -= (1<<k);
        }
        ps(res);
    }
}
