#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> snippets;
string line;

int main() {
    ios_base::sync_with_stdio(false);
    
    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s, snippets.push_back(s);
    }
    getline(cin, line);
    getline(cin, line);
    
    // check if all snippets are in the line
    bool works = true;
    for (string sni : snippets) {
        if (line.find(sni) == -1)
            works = false;
        else
            line.replace(line.find(sni), sni.size(), "*");
    }
    
    // output
    if (works)
        cout << "Potentially!\n";
    else
        cout << "No, No, No!!!\n";
    
    return 0;
}
