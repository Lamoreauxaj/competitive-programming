#include <bits/stdc++.h>
using namespace std;

string A, B;

string add(string A, string B) {
    string res = "";
    int carry = 0;
    for (int i = 0; i < max(A.size(), B.size()); i++) {
        int a = i < A.size() ? A[A.size() - i - 1] - '0' : 0;
        int b = i < B.size() ? B[B.size() - i - 1] - '0' : 0;
        res += (char) ((a + b + carry) % 10 + '0');
        carry = (a + b + carry) / 10;
    }
    if (carry)
        res += (char) (carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> A >> B;
    cout << add(A, B) << "\n";

    return 0;
}
