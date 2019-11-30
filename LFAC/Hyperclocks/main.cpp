#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;
const int MOD = 1000000007;
const ld EPS = 1e-9;
const ld PI = acos(-1);

#define x first
#define y second

#define pc(x) putchar_unlocked(x);
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

#define MAX_N 30

int N, K[MAX_N], idx[MAX_N];

void move(int p, int fwd) {
    writeInt(idx[p]);
    pc(' ');
    if (!fwd) pc('-');
    pc('1');
    pc('\n');
}

void trav(int p, int fwd) {
    if (p == N) return;
    int k = K[p], alt = 1;
    if (k == 1)
        trav(p + 1, 1);
    else if (p < N - 1 && k % 2 != 0) {
        int kn = K[p + 1];
        trav(p + 2, alt), alt = !alt;
        for (int i = 0; i < kn; i++) {
            if (i) {
                move(p + 1, 1);
                // printf("%d %d\n", idx[p + 1], 1);
                trav(p + 2, alt), alt = !alt;
            }
            move(p, i % 2 == 0 ? fwd : !fwd);
            // printf("%d %d\n", idx[p], 2 * (i % 2 == 0 ? fwd : !fwd) - 1);
            trav(p + 2, alt), alt = !alt;
        }
        move(p, fwd);
        // printf("%d %d\n", idx[p], 2 * fwd - 1);
        k -= 2;
        alt = 0;
    }
    for (int i = 0; i < k - 1; i++) {
        trav(p + 1, alt), alt = !alt;
        // printf("%d %d\n", idx[p], 2 * fwd - 1);
        move(p, fwd);
    }
    trav(p + 1, alt), alt = !alt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(10);

    // input
    scanf("%d", &N);

    // sort by even then odd
    // this ensures that odd numbers are followed by odd
    int ep = 0, op = N - 1;
    // ll p = 1;
    for (int i = 0; i < N; i++) {
        int a; scanf("%d", &a);
        if (a % 2 == 0) K[ep] = a, idx[ep++] = i + 1;
        else K[op] = a, idx[op--] = i + 1;
        // p *= a;
    }

    // ll start = clock();
    
    // assert(p <= 900000);

    trav(0, 1);
    move(0, 1);
    // printf("%d %d\n", idx[0], 1);

    // printf("%.5f\n", double(clock() - start) / CLOCKS_PER_SEC);

    return 0;
}
