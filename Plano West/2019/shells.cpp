#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int TC; cin >> TC;
    while (TC--) {
        // input
        int B, G; cin >> B >> G;
        
        // decide if open
        if (B % 2 == 0 || G % 2 != 0 || B + G < 10)
            cout << "CLOSED\n";
        else
            cout << "OPEN\n";
    }
    
    return 0;
}
