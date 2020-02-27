#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;
using str=string;
using pi=pair<int, int>;
using pl=pair<ll, ll>;
using pd=pair<ld, ld>;
template <class T> using vec=vector<T>;
using vb=vec<bool>;
using vi=vec<int>;
using vl=vec<ll>;
using vd=vec<ld>;
using vs=vec<str>;
template<class T, class U> using umap=unordered_map<T, U>;
template<class T> using uset=unordered_set<T>;
#define repr(i, a, b) for (int i = (a); i != (b); i += (a < b ? 1 : -1))
#define rep(i, a) repr(i, 0, a)
#define trav(i, a) for (auto& i : a)
#define sz(x) (int)(x.size())
#define beg begin
#define all(x) beg(x), end(x)
#define rsz resize
#define asn assign
#define clr clear
#define pb push_back
#define ins insert
#define pb push_back
#define pf push_front
#define bk back
#define fr front
#define lb lower_bound
#define ub upper_bound
#define x first
#define y second

int MOD = 1e9+7, MX = 5e5+5;
ll INF = 1e18;
ld PI = acos((ld)-1), EPS = 1e-8;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


namespace input {
    template<class T> inline void re(complex<T>& x);
    template<class T1, class T2> inline void re(pair<T1,T2>& p);
    template<class T> inline void re(vector<T>& a);
    template<class T, size_t SZ> inline void re(array<T,SZ>& a);

    template<class T> inline void re(T& x) { cin >> x; }
    inline void re(double& x) { string t; re(t); x = stod(t); }
    inline void re(ld& x) { string t; re(t); x = stold(t); }
    template<class T, class... Ts> inline void re(T& t, Ts&... ts) { 
        re(t); re(ts...); 
    }

    template<class T> inline void re(complex<T>& x) { T a,b; re(a,b); x = {a,b}; }
    template<class T1, class T2> inline void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> inline void re(vector<T>& a) { rep(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> inline void re(array<T,SZ>& a) { rep(i,SZ) re(a[i]); }
    inline void setin(string s) { freopen(s.c_str(), "r", stdin); }
}

namespace output {
    inline void pr(int x) { cout << x; }
    inline void pr(long x) { cout << x; }
    inline void pr(ll x) { cout << x; }
    inline void pr(unsigned x) { cout << x; }
    inline void pr(unsigned long x) { cout << x; }
    inline void pr(unsigned long long x) { cout << x; }
    inline void pr(float x) { cout << x; }
    inline void pr(double x) { cout << x; }
    inline void pr(ld x) { cout << x; }
    inline void pr(char x) { cout << x; }
    inline void pr(const char* x) { cout << x; }
    inline void pr(const string& x) { cout << x; }
    inline void pr(bool x) { pr(x ? "true" : "false"); }
    template<class T> inline void pr(const complex<T>& x) { cout << x; }
    
    template<class T1, class T2> inline void pr(const pair<T1,T2>& x);
    template<class T> inline void pr(const T& x);
    
    template<class T, class... Ts> inline void pr(const T& t, const Ts&... ts) { 
        pr(t); pr(ts...); 
    }
    template<class T1, class T2> inline void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> inline void pr(const T& x) { 
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
        pr("}");
    }
    
    inline void ps() { pr("\n"); }
    template<class T, class... Ts> inline void ps(const T& t, const Ts&... ts) { 
        pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
    }
    
    inline void pc() { pr("]\n"); }
    template<class T, class... Ts> inline void pc(const T& t, const Ts&... ts) { 
        pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
    }
    #ifdef LOCAL
    #define dbg(x...) pr("[",#x,"] = ["), pc(x);
    #else
    #define dbg(x...) 0
    #endif

    inline void setout(string s) { freopen(s.c_str(), "w", stdout); }
}

using namespace input;
using namespace output;

void solve();

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    solve();
    return 0;
}

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
