#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

struct UnionFind {
    vector<int> p, rank, v, an;
    UnionFind(int N) {
        p.assign(N, 0);
        rank.assign(N, 0);
        v.assign(N, 0);
        an.assign(N, 1);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    void updateVal(int i, int k) {
        v[find(i)] = k;
    }
    int val(int i) {
        return v[find(i)];
    }
    void updateAns(int i, int k) {
        an[find(i)] = k;
    }
    int ans(int i) {
        return an[find(i)];
    }
    int find(int i) {
        return p[i] == i ? i : (p[i] = find(p[i]));
    }
    bool merge(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false;
        if (rank[x] < rank[y]) {
            p[x] = y;
        }
        else {
            p[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
        return true;
    }
};

struct Edge {
    int a, b, w;
    bool operator < (const Edge& other) const {
        return w < other.w;
    }
};

int N, M, H;
vector<Edge> edges;
vector<vector<int>> ver, hor;

int main() {
    ios_base::sync_with_stdio(false);

    // take in input
    cin >> N >> M >> H;
    ver.assign(N, vector<int>(M - 1));
    hor.assign(N - 1, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M - 1; j++) {
            cin >> ver[i][j];
            edges.push_back(Edge{i * M + j, i * M + j + 1, ver[i][j]});
        }
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < M; j++) {
            cin >> hor[i][j];
            edges.push_back(Edge{i * M + j, i * M + j + M, hor[i][j]});
        }

    // sort edges
    sort(edges.begin(), edges.end());

    // run union find
    UnionFind uf(N * M);
    for (Edge e : edges) {
        if (uf.find(e.a) == uf.find(e.b)) continue;
        if (uf.val(e.a) < e.w) {
            uf.updateAns(e.a, ((long long) e.w - uf.val(e.a) + uf.ans(e.a)) % MOD);
            uf.updateVal(e.a, e.w);
        }
        if (uf.val(e.b) < e.w) {
            uf.updateAns(e.b, ((long long) e.w - uf.val(e.b) + uf.ans(e.b)) % MOD);
            uf.updateVal(e.b, e.w);
        }
        long long tmp = (long long) uf.ans(e.a) * uf.ans(e.b) % MOD;
        uf.merge(e.a, e.b);
        uf.updateAns(e.a, (int) tmp);
    }

    // output
    cout << ((long long) H - uf.val(0) + uf.ans(0)) % MOD << "\n";

    return 0;
}
