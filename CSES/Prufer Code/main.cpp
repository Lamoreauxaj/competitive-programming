#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> pru;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    pru.assign(N - 2, 0);
    for (int i = 0; i < N - 2; i++) cin >> pru[i];

    set<int> avail;
    unordered_map<int, int> freq;
    vector<bool> used(N + 1);
    for (int i = 0; i < N - 2; i++) freq[pru[i]]++;
    for (int i = 1; i <= N; i++) if (!freq.count(i)) avail.insert(i);
    for (int i = 0; i < N - 2; i++) {
        int v = *avail.begin();
        cout << v << " " << pru[i] << "\n";
        used[v] = true;
        avail.erase(avail.begin());
        freq[pru[i]]--;
        if (!freq[pru[i]])
            avail.insert(pru[i]);
    }

    bool first = true;
    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            if (!first) cout << " "; first = false;
            cout << i;
        }
    }
    cout << "\n";

    return 0;
}
