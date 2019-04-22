#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    vector<vector<int>> sets;
    for (int i = 1; i <= N; i++) {
        if (sets.size() == 0)
            sets.push_back({i});
        else {
            cout << sets.size() + 1;
            for (auto v : sets)
                cout << " " << v[0];
            cout << " " << i;
            cout << endl;
            int res; cin >> res;
            if (res > sets.size())
                sets.push_back({i});
            else {
                int lo = 0, hi = sets.size() - 1;
                while (lo < hi) {
                    int m = (lo + hi) / 2;
                    cout << m - lo + 1 + 1;
                    for (int i = lo; i <= m; i++)
                        cout << " " << sets[i][0];
                    cout << " " << i;
                    cout << endl;
                    int res; cin >> res;
                    if (res == m - lo + 1)
                        hi = m;
                    else
                        lo = m + 1;
                }
                sets[lo].push_back(i);
            }
        }
    }

    vector<int> res(N);
    for (int i = 0; i < sets.size(); i++) {
        for (int v : sets[i])
            res[v - 1] = i + 1;
    }
    cout << "0";
    for (int i : res)
        cout << " " << i;
    cout << "\n";

    return 0;
}
