#include <bits/stdc++.h>
using namespace std;

struct Event {
    int x; bool st;
    bool operator < (Event& other) const {
        if (x == other.x) return st > other.st;
        return x < other.x;
    }
};

int N;
vector<Event> events;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        events.push_back(Event{s, true});
        events.push_back(Event{e, false});
    }

    sort(events.begin(), events.end());

    int open = 0, last = -1, ans = 0;
    for (int i = 0; i < events.size(); i++) {
        if (open) ans += events[i].x - last;
        if (events[i].st) open++;
        else open--;
        if (events[i].st && open == 1) ans++;
        last = events[i].x;
    }

    cout << ans << "\n";

    return 0;
}
