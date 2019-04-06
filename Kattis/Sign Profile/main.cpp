#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-12;

long double val(vector<long double>& c, long double x) {
    long double p = 1, res = 0;
    for (int i = 0; i < c.size(); i++) {
        res += c[i] * p;
        p *= x;
    }
    return res;
}

long double der(vector<long double>& c, long double x) {
    long double p = 1, res = 0;
    for (int i = 1; i < c.size(); i++) {
        res += i * p * c[i];
        p *= x;
    }
    return res;
}

pair<vector<long double>, long double> divide(vector<long double>& c, long double root) {
    vector<long double> res;
    res.push_back(c[c.size() - 1]);
    for (int i = c.size() - 2; i > 0; i--) {
        res.push_back(c[i] + res.back() * root);
    }
    long double rem = c[0] + res.back() * root;
    reverse(res.begin(), res.end());
    return {res, rem};
}

vector<long double> roots(vector<long double> c) {
    vector<long double> res;
    while (c.size() > 1) {
        long double last;
        long double r = rand() / 500.0;
        for (int i = 0; i < 250; i++) {
            r -= val(c, r) / der(c, r);
            last = r;
        }
        auto div = divide(c, r);
        c = div.first;
        if (abs(div.second) > EPS) break;
        res.push_back(r);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    while (true) {
        vector<long double> c(4);
        cin >> c[0] >> c[1] >> c[2] >> c[3];
        bool nonzero = false;
        for (int i = 0; i < 4; i++)
            if (abs(c[i]) > EPS) nonzero = true;
        if (!nonzero) break;

        while (!c.empty() && abs(c.back()) < EPS) c.pop_back();

        vector<long double> res = roots(c);

        sort(res.begin(), res.end());
        vector<int> counts;
        int cnt = 1;
        for (int i = 1; i <= res.size(); i++) {
            if (i == res.size() || abs(res[i] - res[i - 1]) > EPS) {
                counts.push_back(cnt);
                cnt = 1;
            }
            else cnt++;
        }

        string ans = "";
        if (c[c.size() - 1] * (c.size() % 2 == 1 ? 1 : -1) < 0) ans += "-";
        else ans += "+";
        for (int i : counts) {
            if (i % 2 != 0) {
                ans += (ans[ans.size() - 1] == '-' ? "+" : "-");
            }
        }

        cout << ans << "\n";

    }

    return 0;
}
