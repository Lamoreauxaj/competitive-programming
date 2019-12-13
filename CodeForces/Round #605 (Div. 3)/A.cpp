#include "cplib.cpp"

void solve() {
    int TC; cin >> TC;
    while (TC--) {
        int v[3];
        cin >> v[0] >> v[1] >> v[2];
        sort(v, v + 3);
        if (v[0] < v[2]) v[0]++;
        if (v[2] > v[0]) v[2]--;
        int d = abs(v[0] - v[2]) * 2;
        cout << d << "\n";
    }
}

int main() {
    cplib("A.cpp");
    testcase("8\n3 3 4\n10 20 30\n5 5 5\n2 4 3\n1 1000000000 1000000000\n1 1000000000 999999999\n3 2 5\n3 2 6\n", "0\n36\n0\n0\n1999999994\n1999999994\n2\n4\n");
    return test();
}