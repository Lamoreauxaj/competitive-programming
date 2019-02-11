#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> label;
vector<vector<int>> child;

vector<bool> visit;

// run dfs to construct a rooted tree from 0
void construct_tree(int pos) {
    for (int i = 0; i < adj[pos].size(); i++) {
        int v = adj[pos][i];
        if (!visit[v]) {
            visit[v] = true;
            child[pos].push_back(v);
            construct_tree(v);
        }
    }
}

vector<int> ans;
unordered_map<int, int> freq;

// dfs and keep track of unique labels in ans
void recurse(int pos) {
    freq[label[pos]]++;
    ans[pos] = freq.size();
    for (int i : child[pos])
        recurse(i);
    freq[label[pos]]--;
    if (freq[label[pos]] == 0)
        freq.erase(label[pos]);
}

int main() {
    ios_base::sync_with_stdio(false);
    
    // input
    cin >> N;
    label.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> label[i];
    adj.assign(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // construct the tree
    child.assign(N, vector<int>());
    visit.assign(N, false);
    visit[0] = 1;
    construct_tree(0);
    
    // recurse
    ans.assign(N, 0);
    recurse(0);
    
    // output
    for (int i : ans)
        cout << i << "\n";
    
    return 0;
}
