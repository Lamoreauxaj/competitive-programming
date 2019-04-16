/*
ID: lamorea1
LANG: C++11
TASK: cline
*/
#include <bits/stdc++.h>
using namespace std;

int N;
deque<int> line;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("cline.in", "r", stdin);
    freopen("cline.out", "w", stdout);

    cin >> N;
    int id = 1;
    for (int i = 0; i < N; i++) {
        char a, b;
        int c;
        cin >> a >> b;
        if (a == 'D') {
            cin >> c;
            for (int j = 0; j < c; j++) {
                if (b == 'L')
                    line.pop_front();
                else
                    line.pop_back();
            }
        }
        else {
            if (b == 'L')
                line.push_front(id++);
            else
                line.push_back(id++);
        }
    }

    for (auto i : line) {
        cout << i << "\n";
    }

    return 0;
}
