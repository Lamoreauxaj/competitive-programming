#include <bits/stdc++.h>
using namespace std;

double M;
int T, C;

int main() {
    ios_base::sync_with_stdio(false);
    
    int TC; cin >> TC;
    while (TC--) {
        // input
        cin >> T >> M >> C;
        
        // krabby patties are total number of 2 combos
        int krab = T - C;
        M -= krab * 1.25;
        
        // solve remaining two variable system
        int money = round(M);
        int kelp = money - C;
        int coral = C - kelp;
        
        // output
        cout << krab << " krabby patties, " << coral << " coral bits, " << kelp << " kelp shakes\n";
    }
    
    return 0;
}
