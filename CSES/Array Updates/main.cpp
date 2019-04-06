#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    struct Node {
        long long v, p, s, t;
        Node() {
            v = p = s = t = 0;
        }
        Node(int vv) {
            v = p = s = max(vv, 0);
            t = vv;
        }
        Node(Node l, Node r) {
            t = l.t + r.t;
            v = max(l.v, r.v);
            v = max(v, l.s + r.p);
            p = max(l.p, l.t + r.p);
            s = max(r.s, r.t + l.s);
        }
    };
    int N; vector<Node> st;
    SegmentTree() {}
    SegmentTree(int NN) {
        N = NN;
        st.assign(N * 2, Node());
        build();
    }
    void build() {
        for (int i = 0; i < N; i++)
            st[i + N] = Node();
        for (int i = N - 1; i; i--)
            st[i] = Node(st[i << 1], st[i << 1 | 1]);
    }
    void update(int k, int x) {
        st[N + k] = Node(x);
        for (k += N; k > 1; k >>= 1)
            st[k >> 1] = Node(st[(k | 1) ^ 1], st[k | 1]);
    }
    long long query(int l, int r) {
        Node rl, rr; r++;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) rl = Node(rl, st[l++]);
            if (r & 1) rr = Node(st[--r], rr);
        }
        return Node(rl, rr).v;
    }
};

int N, M;
SegmentTree tree;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    tree = SegmentTree(N);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        tree.update(i, a);
    }

    for (int i = 0; i < M; i++) {
        int k, x; cin >> k >> x;
        tree.update(k - 1, x);
        cout << tree.query(0, N - 1) << "\n";
    }

    return 0;
}
