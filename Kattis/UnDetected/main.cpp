#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> p, rank;
    UnionFind(int N) {
        p.assign(N, 0);
        rank.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int find(int i) {
        return p[i] == i ? i : (p[i] = find(p[i]));
    }
    bool merge(int i, int j) {
        if (find(i) != find(j)) {
            int x = find(i), y = find(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
            }
            else {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
            return true;
        }
        return false;
    }
};

struct Circle {
    int x, y, r;
};

int N;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    UnionFind uf(N + 2);

    vector<Circle> circles;
    int ans = -1;
    for (int i = 0; i < N && ans < 0; i++) {
        Circle c; cin >> c.x >> c.y >> c.r;
        if (c.x - c.r <= 0)
            uf.merge(N, i);
        if (c.x + c.r >= 200)
            uf.merge(N + 1, i);
        int j = 0;
        for (Circle circ : circles) {
            int d = (circ.x - c.x) * (circ.x - c.x) + (circ.y - c.y) * (circ.y - c.y);
            if (d <= (circ.r + c.r) * (circ.r + c.r))
                uf.merge(i, j);
            j++;
        }
        circles.push_back(c);
        if (uf.find(N) == uf.find(N + 1)) {
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}
