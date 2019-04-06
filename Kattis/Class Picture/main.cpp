#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> names;
map<string, unordered_set<string>> adj;

vector<string> sol;
unordered_set<string> used;

bool recurse(string curr) {
    if (used.size() == names.size()) {
        bool first = true;
        for (string s : sol) {
            if (!first) cout << " ";
            first = false;
            cout << s;
        }
        cout << "\n";
        return true;
    }
    for (string s : names) {
        if (!used.count(s) && !adj[curr].count(s)) {
            sol.push_back(s);
            used.insert(s);
            if (recurse(s))
                return true;
            sol.pop_back();
            used.erase(s);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("1.in", "r", stdin);

    while (cin >> N) {
        names.assign(N, "");
        for (int i = 0; i < N; i++) cin >> names[i];
        cin >> M;
        for (int i = 0; i < M; i++) {
            string a, b; cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        sort(names.begin(), names.end());
        sol.clear();
        used.clear();

        bool works = false;
        for (string s : names) {
            sol.push_back(s);
            used.insert(s);
            if (recurse(s)) {
                works = true;
                break; 
            }
            sol.pop_back();
            used.erase(s);
        }
        if (!works) cout << "You all need therapy.\n";
    }

    return 0;
}
