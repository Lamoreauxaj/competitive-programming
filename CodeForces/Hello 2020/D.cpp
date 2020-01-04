#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> A[100010], B[100010];

bool process(pair<int, int>* A, pair<int, int>* B) {
    vector<pair<int, pair<bool, int>>> evts;
    for (int i = 0; i < N; i++) {
        evts.push_back({A[i].first, {true, i}});
        evts.push_back({A[i].second, {false, i}});
    }


    sort(evts.begin(), evts.end());

    multiset<int> ostarts, oends;
    bool good = true;
    for (auto e : evts) {
        /*
        cout << e.first << " " << e.second.first << " " << e.second.second << endl;
        cout << "ostarts: ";
        for (int i : ostarts) cout << i << " ";
        cout << endl;
        cout << "oends: ";
        for (int i : oends) cout << i << " ";
        cout << endl;
        */
        if (e.second.first) {
            int x = B[e.second.second].first;
            int y = B[e.second.second].second;
            if (ostarts.size()) {
                int mxstart = *(--ostarts.end());
                int mnend = *(oends.begin());
                if (mnend <= x || mxstart >= y) good = false;
            }
            ostarts.insert(B[e.second.second].first);
            oends.insert(B[e.second.second].second);
        }
        else {
            ostarts.erase(ostarts.find(B[e.second.second].first));
            oends.erase(oends.find(B[e.second.second].second));
        }
    }
    return good;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second >> B[i].first >> B[i].second;
        A[i].second++;
        B[i].second++;
    }

    bool good = process(A, B) && process(B, A);
    
    if (good) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
