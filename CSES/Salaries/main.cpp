#include <bits/stdc++.h>
using namespace std;

struct Treap {
    struct Node {
        int key, prior, size;
        long long sum;
        Node *left, *right;
        Node() {}
        Node(int k) {
            key = k;
            prior = rand() + (rand() << 15);
            left = right = NULL;
            size = 1;
            sum = k;
        }
    };

    static void update(Node* tree) {
        if (tree)
            tree->size = 1 + (tree->left == NULL ? 0 : tree->left->size) + (tree->right == NULL ? 0 : tree->right->size);
        if (tree)
            tree->sum = tree->key + (tree->left == NULL ? 0 : tree->left->sum) + (tree->right == NULL ? 0 : tree->right->sum);
    }

    static void split(Node* tree, int key, Node*& left, Node*& right) {
        if (!tree)
            left = right = NULL;
        else if (key < tree->key)
            split(tree->left, key, left, tree->left), right = tree;
        else
            split(tree->right, key, tree->right, right), left = tree;
        update(tree);
    }

    static void insertH(Node*& tree, Node* it) {
        if (!tree)
            tree = it;
        else if (it->prior > tree->prior)
            split(tree, it->key, it->left, it->right), tree = it;
        else
            insertH(it->key < tree->key ? tree->left : tree->right, it);
        update(tree);
    }

    static void insert(Node*& tree, int v) {
        insertH(tree, new Node(v));
    }

    static void merge(Node*& tree, Node* left, Node* right) {
        if (!left || !right)
            tree = left ? left : right;
        else if (left->prior > right->prior)
            merge(left->right, left->right, right), tree = left;
        else
            merge(right->left, left, right->left), tree = right;
        update(tree);
    }

    static void erase(Node*& tree, int key) {
        if (!tree) return;
        if (tree->key == key)
            merge(tree, tree->left, tree->right);
        else
            erase(key < tree->key ? tree->left : tree->right, key);
        update(tree);
    }

    static int get(Node* tree, int ind) {
        int leftSize = (tree->left ? tree->left->size : 0);
        if (ind < leftSize)
            return get(tree->left, ind);
        else if (ind > leftSize)
            return get(tree->right, ind - leftSize - 1);
        else
            return tree->key;
    }

    static int lowerBound(Node* tree, int x) {
        if (!tree) return 0;
        int rightSize = (tree->right ? tree->right->size : 0);
        if (x <= tree->key)
            return rightSize + 1 + lowerBound(tree->left, x);
        else
            return lowerBound(tree->right, x);
    }

    static int upperBound(Node* tree, int x) {
        if (!tree) return 0;
        int rightSize = (tree->right ? tree->right->size : 0);
        if (x < tree->key)
            return rightSize + 1 + upperBound(tree->left, x);
        else
            return upperBound(tree->right, x);
    }
};

int N, Q;
Treap::Node* tree;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> Q;
    v.assign(N, 0);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v[i] = a;
        Treap::insert(tree, a);
    }

    for (int i = 0; i < Q; i++) {
        char a; cin >> a;
        int x, y; cin >> x >> y;
        if (a == '!')
            Treap::erase(tree, v[x - 1]), Treap::insert(tree, y), v[x - 1] = y;
        else
            cout << Treap::lowerBound(tree, x) - Treap::upperBound(tree, y) << "\n";
    }

    return 0;
}
