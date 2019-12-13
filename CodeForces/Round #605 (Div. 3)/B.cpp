#include "cplib.cpp"

void solve() {
    int TC; cin >> TC;
    while (TC--) {
        string S; cin >> S;
        unordered_map<char, int> cnt;
        for (char c : S)
            cnt[c]++;
        int lr = min(cnt['L'], cnt['R']), ud = min(cnt['U'], cnt['D']);
        if (lr == 0 && ud == 0) cout << 0 << "\n\n";
        else {
            if (lr == 0) {
                cout << "2\n";
                cout << "UD\n";
            }
            else if (ud == 0) {
                cout << "2\n";
                cout << "RL\n";
            }
            else {
                cout << lr * 2 + ud * 2 << "\n";
                for (int j = 0; j < lr; j++)
                    cout << "R";
                for (int j = 0; j < ud; j++)
                    cout << "U";
                for (int j = 0; j < lr; j++)
                    cout << "L";
                for (int j = 0; j < ud; j++)
                    cout << "D";
                cout << "\n";
            }
        }
    }
}

int main() {
    cplib("B.cpp");
    testfile("B1.in", "B1.out");
    return test();
}