#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

struct SegmentTree {
    struct Node {
        int v;
        Node() {
            v = INF;
        }
        Node(int vv) {
            v = vv;
        }
        Node(Node l, Node r) {
            v = min(l.v, r.v);
        }
    };
    vector<int> arr;
    vector<Node> st;
    SegmentTree(vector<int> ar) {
        arr = ar;
        st.assign(arr.size() * 2, Node());
        build();
    }
    void build() {
        for (int i = 0; i < arr.size(); i++)
            st[i + arr.size()] = Node(arr[i]);
        for (int i = arr.size() - 1; i > 0; i--)
            st[i] = Node(st[i << 1], st[i << 1 | 1]);
    }
    int query(int l, int r) {
        Node res; r++;
        for (l += arr.size(), r += arr.size(); l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = Node(res, st[l++]);
            if (r & 1) res = Node(st[--r], res);
        }
        return res.v;
    }
};

int R, C;
vector<string> grid;
vector<vector<int>> nextRight;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("1.in", "r", stdin);

    cin >> R >> C;
    grid.assign(R, "");
    for (int i = 0; i < R; i++) cin >> grid[i];

    nextRight.assign(R, vector<int>(C, 0));

    for (int k = C - 1; k >= 0; k--) {
        for (int i = 0; i < R; i++) {
            if (grid[i][k] == '*')
                nextRight[i][k] = k;
            else
                nextRight[i][k] = (k == C - 1 ? C : nextRight[i][k + 1]);
        }
    }

    vector<vector<int>> ans(R, vector<int>(C));

    for (int c1 = 0; c1 < C; c1++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> stars;
        for (int r = 0; r < R; r++)
            stars.push({nextRight[r][c1], r});
        vector<int> currNextRight(R);
        for (int r = 0; r < R; r++)
            currNextRight[r] = nextRight[r][c1];
        cout << "currNextRight: ";
        for (int i : currNextRight) cout << i << " "; cout << "\n";
        SegmentTree t(currNextRight);
        ans[R - 1][t.query(0, R - 1)]++;

        set<int> currentStars;
        currentStars.insert(-1);
        currentStars.insert(R);

        cout << "Trying col c1: " < c1 << "\n";
        for (int c2 = c1; c2 < C; c2++) {
            while (stars.size() && stars.top().first <= c2) {
                int v = stars.top().second;
                auto it = currentStars.lower_bound(stars.top().second);
                int r = *it; it--;
                int l = *it;
                cout << "Adding star at col: " << stars.top().first << " at row: " << v << " bordered by l, r: " << l << ", " << r << "\n";
                if (v > l + 1) {
                    int q = t.query(l + 1, v - 1);
                    cout << "Running left and got: " << q - c1 << " with a R of " << v - l - 2 + 1 << " and C of " << c2 - c1 + 1 << "\n";
                    colSums[q - c1]++;
                    colSums[stars.top().second]--;
                    ans[v - l - 2][c2 - c1] += t.query(l + 1, v - 1) - c1;
                }
                if (r > v + 1) {
                    cout << "Running right\n";
                    ans[r - v - 2][c2 - c1] += t.query(v + 1, r - 1) - c1;
                }
                currentStars.insert(v);
                stars.pop();
            }
            cout << "Trying col c2: " << c2 << "\n";
            cout << "Current stars:";
            for (int i : currentStars)
                cout << " " << i;
            cout << "\n";
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (j) cout << " ";
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}
