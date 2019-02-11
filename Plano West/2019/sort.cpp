#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> S;

unordered_map<char, vector<char>> child;
unordered_map<char, int> in_degree;

// count strongly connected components using Tarjans
unordered_map<char, int> dfs_num, dfs_low, visited;
vector<char> St;
int dfsNumberCounter;
int numSCC;
void tarjanSCC(char u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    St.push_back(u);
    visited[u] = 1;
    for (int j = 0; j < (int) child[u].size(); j++) {
        char v = child[u][j];
        if (dfs_num[v] == -1)
            tarjanSCC(v);
        if (visited[v])
            dfs_num[u] = min(dfs_low[u], dfs_low[v]);
    }
    
    if (dfs_low[u] == dfs_num[u]) {
        numSCC++;
        while (1) {
            char v = St.back(); St.pop_back();
            visited[v] = 0;
            if (u == v) break;
        }
    }
        
}

// check if the graph has 26 strongly connected components
bool has_cycles() {
    for (char c = 'A'; c <= 'Z'; c++)
        dfs_num[c] = -1;
    dfs_low.clear();
    visited.clear();
    dfsNumberCounter = numSCC = 0;
    for (char c = 'A'; c <= 'Z'; c++)
        if (dfs_num[c] == -1)
            tarjanSCC(c);
    if (numSCC == 26)
        return false;
    return true;
}

unordered_map<char, int> prior;
unordered_map<char, int> prior_tree;

// calculate minimum lexicographically priority in each subtree of the DAG
int recurse(char pos) {
    if (prior_tree.count(pos))
        return prior_tree[pos];
    prior_tree[pos] = prior[pos];
    for (char i : child[pos])
        prior_tree[pos] = min(prior_tree[pos], recurse(i));
    return prior_tree[pos];
}

int main() {
    
    // input
    cin >> N;
    S.assign(N, "");
    for (int i = 0; i < N; i++)
        cin >> S[i];
    
    // calculate lexicographic priority
    for (int i = 0; i < N; i++) {
        string A = S[i];
        for (char c : A) {
            if (!prior.count(c))
                prior[c] = prior.size();
        }
    }
    for (char c = 'A'; c <= 'Z'; c++)
        if (!prior.count(c))
            prior[c] = prior.size();
    
    // construct graph from the input
    for (int i = 0; i < N - 1; i++) {
        string A = S[i];
        string B = S[i + 1];
        int x = 0;
        while (x < A.size() && x < B.size()) {
            if (A[x] != B[x]) {
                child[A[x]].push_back(B[x]);
                in_degree[B[x]]++;
                break;
            }
            x++;
        }
    }
    
    // check for cycles
    if (has_cycles()) {
        cout << "No Solution\n";
        return 0;
    }
    
    // construct tree priority
    for (char c = 'A'; c <= 'Z'; c++)
        recurse(c);
    
    // initialize pq
    priority_queue<pair<int, char>> to_add;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (in_degree[c] == 0)
            to_add.push({-prior_tree[c], c});
    }
    
    // find lexicographically smallest mapping using pq
    unordered_map<char, char> result;
    char curr = 'A';
    while (!to_add.empty()) {
        auto t = to_add.top(); to_add.pop();
        int p = -t.first;
        char c = t.second;
        result[c] = curr;
        for (char v : child[c]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                to_add.push({-prior_tree[v], v});
            }
        }
        curr++;
    }
    
    // output
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S[i].size(); j++)
            cout << result[S[i][j]];
        cout << "\n";
    }
    
    return 0;
}
