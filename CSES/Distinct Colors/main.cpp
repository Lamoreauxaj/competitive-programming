#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    struct Node {

        Node() {}
    };
    vector<int> A;
    vector<Node> st;
    SegmentTree(vector<int> a) {
        A = a;
        st.assign(2 * A.size(), Node());
        build();
    }
    void build() {
        for (int i = 0; i < A.size(); i++)
            st[i + A.size()] = new Node(A[i]);
    }
};

struct EulerTour {
    vector<int> tour, first;
    EulerTour(const vector<vector<int>>& adj) {
        first.assign(adj.size(), 0);

    }
    void dfs(int i, int p) {
        if (first[i] == -1)
            first[i] = tour.size();
        tour.push_back(i);
        for (int j = 0; j < adj[i].size(); j++)
            if (adj[i][j] != p)
                dfs(adj[i][j], i),
                tour.push_back(i);
    }
};

int N;
vector<vector<int>> adj;
vector<int> color;

vector<int> eulerTour;
vector<int> first;
void findEulerTour(int i, int p) {
    if (first[i] == -1)
        first[i] = eulerTour.size();
    eulerTour.push_back(i);
    for (int j = 0; j < adj[i].size(); j++) {
        if (adj[i][j] != p) {
            findEulerTour(adj[i][j], i);
            eulerTour.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    adj.assign(N, vector<int>());
    color.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> color[i];
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    first.assign(N, -1);
    findEulerTour(0, 0);

    return 0;
}
