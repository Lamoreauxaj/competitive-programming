#include <bits/stdc++.h>
using namespace std;

double T, P, S;

int main() {
    ios_base::sync_with_stdio(false);
    
    int TC; cin >> TC;
    while (TC--) {
        // input
        cin >> T >> P >> S;
        
        // solve
        double time = sqrt(P * P * T * T / (S * S - P * P)) + T;
        
        // output
        cout << fixed << setprecision(7) << time << "\n";
    }
    
    return 0;
}
