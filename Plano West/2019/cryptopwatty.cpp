#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int TC; cin >> TC;
    
    // construct map
    string key; cin >> key;
    unordered_map<char, char> sub;
    for (char c = 'A'; c <= 'Z'; c++)
        sub[key[c - 'A']] = c;
    
    // process lines
    string line; getline(cin, line);
    while (TC--) {
        getline(cin, line);
        
        // output new chars
        for (char c : line)
            if (c >= 'A' && c <= 'Z')
                cout << sub[c];
            else
                cout << c;
        cout << "\n";
    }
    
    return 0;
}
