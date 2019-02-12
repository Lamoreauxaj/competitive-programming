#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> H, L, R;

int main() {
    ios_base::sync_with_stdio(false);
    
    // input
    cin >> N;
    H.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> H[i];

    // calculate closest left and right less than each element
    L.assign(N, 0);
    R.assign(N, 0);
    vector<pair<int, int>> st;
    for (int i = 0; i < N; i++) {
        while (st.size() && st.back().first >= H[i])
            st.pop_back();
        if (st.empty())
            L[i] = -1;
        else
            L[i] = st.back().second;
        st.push_back({H[i], i});
    }
    st.clear();
    for (int i = N - 1; i >= 0; i--) {
        while (st.size() && st.back().first >= H[i])
            st.pop_back();
        if (st.empty())
            R[i] = N;
        else
            R[i] = st.back().second;
        st.push_back({H[i], i});
    }

    // find largest rectangle
    long long area = 0;
    for (int i = 0; i < N; i++) {
        long long wid = R[i] - L[i] - 1;
        area = max(area, H[i] * wid);
    }

    // output
    cout << area << "\n";

    return 0;
}
