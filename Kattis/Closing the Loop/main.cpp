#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        int N; cin >> N;
        priority_queue<int> red, blue;
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            int v = stoi(s.substr(0, s.size() - 1));
            if (s[s.size() - 1] == 'B')
                blue.push(v);
            else
                red.push(v);
        }

        int ans = 0;
        while (!red.empty() && !blue.empty())
            ans += red.top() + blue.top() - 2, red.pop(), blue.pop();
        cout << "Case #" << tc << ": ";
        cout << ans << "\n";
    }

    return 0;
}
