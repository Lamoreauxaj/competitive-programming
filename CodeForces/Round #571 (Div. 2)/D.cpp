#include <bits/stdc++.h>
using namespace std;

int N;
double A[100010];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    long long minSum = 0;
    for (int i = 0; i < N; i++) {
        minSum += floor(A[i]);
    }

    for (int i = 0; i < N; i++) {
        if (minSum < 0 && floor(A[i]) != ceil(A[i]))
            cout << ceil(A[i]) << "\n", minSum++;
        else
            cout << floor(A[i]) << "\n";
    }

    return 0;
}
