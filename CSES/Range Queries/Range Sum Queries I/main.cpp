#include "contest/template.cpp"

int N, Q;
vector<ll> x, psum;

void solve() {
    re(N, Q);
    x.rsz(N); re(x);
    psum.asn(N+1,0);
    repr(i,1,N+1) psum[i] = psum[i-1]+x[i-1];
    int a, b;
    rep(i, Q) {
        re(a, b);
        ps(psum[b]-psum[a-1]);
    }
}
