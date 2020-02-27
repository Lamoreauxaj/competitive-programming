#include "contest/template.cpp"

struct SegTree {
    int N; vi tr;
    SegTree(int N): N(N) {
        tr.asn(2*N,MOD);
    }
    void upd(int p,int v) {
        for(tr[p+=N]=v;p>1;p>>=1)
            tr[p>>1]=min(tr[p],tr[p^1]);
    }
    int qry(int l,int r) {
        int res=MOD; r++;
        for(l+=N,r+=N;l<r;l>>=1,r>>=1) {
            if(l&1) res=min(res,tr[l++]);
            if(r&1) res=min(res,tr[--r]);
        }
        return res;
    }
};

int N,Q;
vi X;
SegTree st(0);

void solve() {
    re(N,Q);
    X.rsz(N); re(X);
    st=SegTree(N);
    rep(i,N) st.upd(i,X[i]);
    rep(q,Q) {
        int t, a, b; re(t,a,b);
        if(t==1) st.upd(a-1,b), X[a-1]=b;
        else ps(st.qry(a-1,b-1));
    }
}
