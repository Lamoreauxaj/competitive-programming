#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> nums;
        int sum = 0, a;
        while (ss >> a)
            sum += a, nums.push_back(a);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] * 2 == sum) {
                cout << nums[i] << "\n";
                break;
            }
        }
    }

    return 0;
}
