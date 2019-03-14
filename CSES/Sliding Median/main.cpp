#include <bits/stdc++.h>
using namespace std;

namespace Treap {
    struct Node {
        int key, prior, size;
        Node *left, *right;
        Node() {}
        Node(int k) {
            key = k;
            prior = rand() + (rand() << 15);
            left = right = NULL;
            size = 1;
        }
        Node(int k, int p) : key(k), prior(p), left(NULL), right(NULL), size(1) {}
        void updateSize() {
            size = (left == NULL ? 0 : left->size) + (right == NULL ? 0 : right->size);
        }
    };

    void updateSize(Node* tree) {
        if (tree)
            tree->size = 1 + (tree->left == NULL ? 0 : tree->left->size) + (tree->right == NULL ? 0 : tree->right->size);
    }

    void split(Node* tree, int key, Node*& left, Node*& right) {
        if (!tree)
            left = right = NULL;
        else if (key < tree->key)
            split(tree->left, key, left, tree->left), right = tree;
        else
            split(tree->right, key, tree->right, right), left = tree;
        updateSize(tree);
    }

    void insert(Node*& tree, Node* it) {
        if (!tree)
            tree = it;
        else if (it->prior > tree->prior)
            split(tree, it->key, it->left, it->right), tree = it;
        else
            insert(it->key < tree->key ? tree->left : tree->right, it);
        updateSize(tree);
    }

    void merge(Node*& tree, Node* left, Node* right) {
        if (!left || !right)
            tree = left ? left : right;
        else if (left->prior > right->prior)
            merge(left->right, left->right, right), tree = left;
        else
            merge(right->left, left, right->left), tree = right;
        updateSize(tree);
    }

    void erase(Node*& tree, int key) {
        if (!tree) return;
        if (tree->key == key)
            merge(tree, tree->left, tree->right);
        else
            erase(key < tree->key ? tree->left : tree->right, key);
        updateSize(tree);
    }

    void recurse(Node* tree, int dep) {
        if (!tree) return;
        recurse(tree->left, dep + 1);
        cout << tree->key << ":" << tree->prior << " at dep: " << dep << " with size: " << tree->size << "\n";
        recurse(tree->right, dep + 1);
    }

    int get(Node* tree, int ind) {
        int leftSize = (tree->left ? tree->left->size : 0);
        if (ind < leftSize)
            return get(tree->left, ind);
        else if (ind > leftSize)
            return get(tree->right, ind - leftSize - 1);
        else
            return tree->key;
    }
};
using namespace Treap;

Node* tree;
int N, K;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }

    for (int i = 0; i < K - 1; i++)
        insert(tree, new Node(arr[i]));


    for (int i = K - 1; i < N; i++) {
        insert(tree, new Node(arr[i]));

        if (i > K - 1)
            cout << " ";
        cout << get(tree, (K - 1) / 2);
        
        erase(tree, arr[i - K + 1]);
    }
    cout << "\n";

    return 0;
}
