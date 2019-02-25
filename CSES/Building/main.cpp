#include <bits/stdc++.h>
using namespace std;

int R, C;
string grid[1000];

int main() {
    ios_base::sync_with_stdio(false);

    // input
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    // find maximum area rectangle
    int area = 0;
    vector<int> height(C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '.') {
                height[j]++;
            }
            else height[j] = 0;
        }
        vector<pair<int, int>> st;
        vector<int> left(C), right(C);
        for (int j = 0; j < C; j++) {
            while (st.size() && st.back().first >= height[j])
                st.pop_back();
            if (st.size())
                left[j] = st.back().second;
            else
                left[j] = -1;
            st.push_back({height[j], j});
        }
        st.clear();
        for (int j = C - 1; j >= 0; j--) {
            while (st.size() && st.back().first >= height[j])
                st.pop_back();
            if (st.size())
                right[j] = st.back().second;
            else
                right[j] = C;
            st.push_back({height[j], j});
        }
        for (int j = 0; j < C; j++) {
            area = max(area, height[j] * (right[j] - left[j] - 1));
        }
    }

    // output
    cout << area << "\n";

    return 0;
}
