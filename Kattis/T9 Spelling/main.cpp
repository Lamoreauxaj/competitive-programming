#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    unordered_map<char, string> keys = {
        {'a', "2"}, {'b', "22"}, {'c', "222"},
        {'d', "3"}, {'e', "33"}, {'f', "333"},
        {'g', "4"}, {'h', "44"}, {'i', "444"},
        {'j', "5"}, {'k', "55"}, {'l', "555"},
        {'m', "6"}, {'n', "66"}, {'o', "666"},
        {'p', "7"}, {'q', "77"}, {'r', "777"}, {'s', "7777"},
        {'t', "8"}, {'u', "88"}, {'v', "888"},
        {'w', "9"}, {'x', "99"}, {'y', "999"}, {'z', "9999"},
        {' ', "0"}
    };

    int TC; cin >> TC;
    string line; getline(cin, line);
    for (int tc = 1; tc <= TC; tc++) {
        getline(cin, line);

        string last = "*";
        cout << "Case #" << tc << ": ";
        for (char c : line) {
            string o = keys[c];
            if (o[0] == last[0]) cout << " ";
            cout << o;
            last = o;
        }
        cout << "\n";
    }

    return 0;
}
