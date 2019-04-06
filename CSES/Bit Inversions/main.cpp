#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    struct Node {
        int val, p0, p1, s0, s1, len;
        Node() {
            val = p0 = p1 = s0 = s1 = len = 0;
        }
        Node(int v) {
            len = val = 1;
            p0 = s0 = (v == 0);
            p1 = s1 = (v == 1);
        }
        Node(Node l, Node r) {
            len = l.len + r.len;
            val = max(l.val, r.val);
            p0 = l.p0 == l.len ? l.len + r.p0 : l.p0;
            p1 = l.p1 == l.len ? l.len + r.p1 : l.p1;
            s0 = r.s0 == r.len ? r.len + l.s0 : r.s0;
            s1 = r.s1 == r.len ? r.len + l.s1 : r.s1;
            val = max(val, max(l.s0 + r.p0, l.s1 + r.p1));
        }
    };
    vector<char> N;
    vector<Node> st;
    SegmentTree() {}
    SegmentTree(string s) {
        for (char c : s)
            N.push_back(c);
        st.assign(N.size() * 2, Node());
        for (int i = 0; i < N.size(); i++)
            st[i + N.size()] = Node(N[i] - '0');
        for (int i = N.size() - 1; i > 0; i--)
            st[i] = Node(st[i << 1], st[i << 1 | 1]);
    }
    Node query(int l, int r) {
        Node res1, res2;
        for (l += N.size(), r += N.size(); l < r; l >>= 1, r >>= 1) {
            if (l & 1) res1 = Node(res1, st[l++]);
            if (r & 1) res2 = Node(st[--r], res2);
        }
        return Node(res1, res2);
    }
    void update(int p) {
        N[p] = (char)('1' - N[p] + '0');
        int v = N[p] - '0';
        for (st[p += N.size()] = Node(v); p > 1; p >>= 1)
            st[p >> 1] = Node(st[(p | 1) ^ 1], st[p | 1]);
    }
};

SegmentTree st;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    string N; cin >> N;
    st = SegmentTree(N);

    int Q; cin >> Q;
    while (Q--) {
        int x; cin >> x;
        st.update(x - 1);
        cout << st.query(0, N.size()).val;
        if (Q) cout << " ";
    }
    cout << "\n";

    return 0;
}
