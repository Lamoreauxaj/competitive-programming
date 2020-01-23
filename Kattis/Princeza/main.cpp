#include <bits/stdc++.h>
using namespace std;

struct Lily {
    int x, y;
    bool operator < (const Lily& o) const {
        return x < o.x;
    }
    bool operator == (const Lily& o) const {
        return x == o.x && y == o.y;
    }
};

int N, K;
string dir;
map<int, set<Lily>> d1;
map<int, set<Lily>> d2;

void del(Lily l) {
    d1[l.x + l.y].erase(l);
    d2[l.x - l.y].erase(l);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> K >> dir;
    Lily curr;
    for (int i = 0; i < N; i++) {
        Lily l; cin >> l.x >> l.y;
        if (i == 0) curr = l;
        d1[l.x + l.y].insert(l);
        d2[l.x - l.y].insert(l);
    }

    for (char c : dir) {
        Lily prev = curr;
        if (c == 'B' || c == 'C') {
            auto it1 = d1[curr.x + curr.y].upper_bound(curr);
            auto it2 = d1[curr.x + curr.y].lower_bound(curr);
            if (c == 'B' && it1 != d1[curr.x + curr.y].end()) {
                curr = *it1;
                del(prev);
            }
            if (c == 'C' && it2 != d1[curr.x + curr.y].begin()) {
                curr = *(--it2);
                del(prev);
            }
        }
        else {
            auto it1 = d2[curr.x - curr.y].upper_bound(curr);
            auto it2 = d2[curr.x - curr.y].lower_bound(curr);
            if (c == 'A' && it1 != d2[curr.x - curr.y].end()) {
                curr = *it1;
                del(prev);
            }
            if (c == 'D' && it2 != d2[curr.x - curr.y].begin()) {
                curr = *(--it2);
                del(prev);
            }
        }
        // cout << curr.x << " " << curr.y << "\n";
    }

    cout << curr.x << " " << curr.y << "\n";

    return 0;
}
