#include <bits/stdc++.h>
using namespace std;

int N;
int A_year, A_days, A;

int main() {
    ios_base::sync_with_stdio(false);
    
    // input
    cin >> N;
    cin >> A_year >> A_days;
    A = A_year * 365 + A_days;
    
    // take in names
    int needed = (N + 2) / 3; // we need >= 1/3 adults
    priority_queue<int> distances;
    for (int i = 0; i < N; i++) {
        string name; cin >> name;
        int Y, D; cin >> Y >> D;
        int V = Y * 365 + D;
        distances.push(-(A - V));
    }
    
    // find max time needed for closest to adults
    int time = 0; // 0 if already satisified
    while (needed--) {
        time = max(time, distances.top() * -1);
        distances.pop();
    }
    
    // output
    cout << time / 365 << " year(s) and " << time % 365 << " day(s)\n";
    
    return 0;
}
