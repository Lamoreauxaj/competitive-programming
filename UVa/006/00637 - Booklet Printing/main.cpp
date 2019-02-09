#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("1.in", "r", stdin);

    while (cin >> N, N) {
        // calculate number of sheets needed
        vector<pair<int, int>> sheets(2 * ((N + 3) / 4));

        // fill in sheets
        int i = 1;
        for (int j = 0; j < sheets.size() && i <= N; j++) {
            if (j % 2 == 0)
                sheets[j].second = i++;
            else
                sheets[j].first = i++;
        }
        for (int j = sheets.size() - 1; j >= 0 && i <= N; j--) {
            if (j % 2 != 0)
                sheets[j].second = i++;
            else
                sheets[j].first = i++;
        }

        // output
        cout << "Printing order for " << N << " pages:\n";
        for (int i = 0; i < sheets.size(); i++) {
            if (!sheets[i].first && !sheets[i].second)
                continue;
            cout << "Sheet " << i / 2 + 1 << ", ";
            if (i % 2 == 0) cout << "front: ";
            else cout << "back : ";
            if (sheets[i].first)
                cout << sheets[i].first;
            else
                cout << "Blank";
            cout << ", ";
            if (sheets[i].second)
                cout << sheets[i].second;
            else
                cout << "Blank";
            cout << "\n";
        }
    }

    return 0;
}
