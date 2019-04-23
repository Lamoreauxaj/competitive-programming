#include <bits/stdc++.h>
using namespace std;

struct Item {
    int w, v, f;
    bool operator < (const Item& other) const {
        if (f == other.f)
            return w > other.w;
        return f < other.f;
    }
};

int N, M;
vector<Item> items;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    cin >> N;
    int maxW = 0;
    for (int i = 0; i < N; i++) {
        int c, f, v; cin >> c >> f >> v;
        items.push_back(Item{-c, -v, f});
        maxW += c;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int c, f, v; cin >> c >> f >> v;
        items.push_back(Item{c, v, f});
    }

    sort(items.begin(), items.end());

    vector<long long> knap(maxW + 1);
    for (int i = 0; i < items.size(); i++) {
        if (items[i].w > 0) {
            for (int j = maxW; j >= items[i].w; j--)
                knap[j] = max(knap[j - items[i].w] + items[i].v, knap[j]);
        }
        else {
            for (int j = 0; j <= maxW + items[i].w; j++)
                knap[j] = max(knap[j - items[i].w] + items[i].v, knap[j]);
        }
    }

    cout << knap[0] << "\n";

    return 0;
}
