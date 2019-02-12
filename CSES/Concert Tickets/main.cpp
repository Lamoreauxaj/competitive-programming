#include <bits/stdc++.h>
using namespace std;

int N, M;
multiset<int> tickets;

int main() {
    ios_base::sync_with_stdio(false);
    
    // input
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        tickets.insert(a);
    }

    // process customers
    for (int i = 0; i < M; i++) {
        int p; cin >> p;
        auto it = tickets.upper_bound(p);
        if (it == tickets.begin())
            cout << "-1\n";
        else {
            it--;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }

    return 0;
}
