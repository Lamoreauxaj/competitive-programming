#include "cplib.cpp"

string A, B;
int memo[510][210][210];
bool par[510][210][210];

int dp(int op, int p1, int p2) {
    if (p1 == A.size() && p2 == B.size()) return op;
    if (memo[op][p1][p2] != -1) return memo[op][p1][p2];
    int res = MOD;
    if (op)
        res = min(res, dp(op - 1, p1 + (p1 < A.size() && A[p1] == ')'), p2 + (p2 < B.size() && B[p2] == ')')) + 1), par[op][p1][p2] = 1;
    int pres = res;
    if (op < 500)
        res = min(res, dp(op + 1, p1 + (p1 < A.size() && A[p1] == '('), p2 + (p2 < B.size() && B[p2] == '(')) + 1);
    if (res < pres) par[op][p1][p2] = 0;
    return memo[op][p1][p2] = res;
}

void solve() {
    cin >> A >> B;
    fill(memo[0][0], memo[509][209] + 210, -1);
    int res = dp(0, 0, 0);
    // cout << res << "\n";
    int op = 0, p1 = 0, p2 = 0;
    while (p1 != A.size() || p2 != B.size()) {
        cout << (par[op][p1][p2] ? ')' : '(');
        if (par[op][p1][p2]) op--, p1 += (p1 < A.size() && A[p1] == ')'), p2 += (p2 < B.size() && B[p2] == ')');
        else op++, p1 += (p1 < A.size() && A[p1] == '('), p2 += (p2 < B.size() && B[p2] == '(');
    }
    while (op) cout << ")", op--;
    cout << "\n";
}

int main() {
    cplib("F.cpp");
    testcase("(())(() ()))()", "(())()()");
    testcase(") ((", "(())");
    testcase(") )))", "((()))");
    testcase("()) (()(()(()(", "(()()()(()()))");
    return test();
}