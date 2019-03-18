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
        Node(int k, int p) : key(k), prior(p), left(NULL), right(NULL), size(1), sum(k) {}
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

    static void insert(Node*& tree, Node* it) {
        if (!tree)
            tree = it;
        else if (it->prior > tree->prior)
            split(tree, it->key, it->left, it->right), tree = it;
        else
            insert(it->key < tree->key ? tree->left : tree->right, it);
        update(tree);
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
};

int N, K;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Treap::Node* tree = NULL;
    for (int i = 0; i < K - 1; i++)
        Treap::insert(tree, new Treap::Node(arr[i]));

    for (int i = K - 1; i < N; i++) {
        Treap::insert(tree, new Treap::Node(arr[i]));
        long long m = Treap::get(tree, (K - 1) / 2);
        Treap::Node *left, *right;
        Treap::split(tree, m, left, right);
        
        long long cost = 0;
        if (left)
            cost += m * left->size - left->sum;
        if (right)
            cost += right->sum - m * right->size;
        if (i > K - 1) cout << " ";
        cout << cost;

        Treap::merge(tree, left, right);
        Treap::erase(tree, arr[i - K + 1]);
    }
    cout << "\n";

    return 0;
}
