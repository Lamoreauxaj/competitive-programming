#include "cplib.cpp"

void solve() {
    string A, B; cin >> A >> B;
    char l = A[A.size() - 1];
    if (l == 'e') cout << A + "x" + B;
    else if (l == 'a' || l == 'i' || l == 'o' || l == 'u') cout << A.substr(0, A.size() - 1) + "ex" + B;
    else if (A.substr(A.size() - 2) == "ex") cout << A + B << "\n";
    else cout << A + "ex" + B << "\n";
}

int main() {
    cplib("main.cpp");
    testcase("menolaxios mox", "menolaxiosexmox");
    testcase("alemaxe maxos", "alemaxexmaxos");
    testcase("pamoli toxes", "pamolextoxes");
    testcase("andrex naxos", "andrexnaxos");
    return test();
}