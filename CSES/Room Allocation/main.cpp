#include <bits/stdc++.h>
using namespace std;

struct Event {
    int x, c;
    bool close;
    bool operator < (const Event& other) const {
        if (x == other.x) return close < other.close;
        return x < other.x;
    }
};

int N;
vector<int> room;
vector<Event> event;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        event.push_back(Event{a, i, false});
        event.push_back(Event{b, i, true});
    }

    sort(event.begin(), event.end());

    int open = 0, ans = 0;
    set<int> avail;
    for (int i = 1; i <= N; i++) avail.insert(i);
    room.assign(N, 0);
    for (int i = 0; i < event.size(); i++) {
        if (event[i].close) {
            open--;
            avail.insert(room[event[i].c]);
        }
        else {
            open++;
            room[event[i].c] = *avail.begin();
            avail.erase(avail.begin());
        }
        ans = max(ans, open);
    }

    cout << ans << "\n";
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << room[i];
    }
    cout << "\n";

    return 0;
}
