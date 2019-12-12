#include "cplib.cpp"

void solve() {
    for (int i = 0; i < 6; i++) {
        if (i) cout << " ";
        int v; cin >> v;
        int r = 2;
        if (i < 2) r = 1;
        if (i > 4) r = 8;
        cout << r - v;
    }
    cout << "\n";
}

int main() {
    cplib("main.cpp");
    testcase("0 1 2 2 2 7", "1 0 0 0 0 1");
    testcase("2 1 2 1 2 1", "-1 0 0 1 0 7");
    return test();
}