#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<pair<int, bool>, int>> events;

int main() {
    ios_base::sync_with_stdio(false);
    
    // input and create events to sort
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        
        events.push_back({{B, true}, A});
        events.push_back({{C, false}, A});
        
    }
    
    // sort events
    sort(events.begin(), events.end());
    
    // find maximum range of knocks
    int last = -1, ans = 0;
    unordered_map<int, int> knocks;
    for (auto e : events) {
        int pos = e.first.first, open = e.first.second;
        int species = e.second;
        if (last != -1) {
            for (auto i : knocks)
                if (i.second % 2 != 0) {
                    ans += pos - last;
                    break;
                }
        }
        if (open)
            knocks[species]++;
        else
            knocks[species]--;
        last = pos;
    }
    
    // output
    cout << ans << "\n";
    
    return 0;
}
