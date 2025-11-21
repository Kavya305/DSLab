// q2_bst_functions.cpp
#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertBST(root->left, key);
    else if (key > root->key) root->right = insertBST(root->right, key);
    // duplicates ignored
    return root;
}

bool searchRecursive(Node* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;
    if (key < root->key) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

bool searchIterative(Node* root, int key) {
    while (root) {
        if (root->key == key) return true;
        if (key < root->key) root = root->left;
        else root = root->right;
    }
    return false;
}

int findMin(Node* root) {
    if (!root) return INT_MIN;
    while (root->left) root = root->left;
    return root->key;
}

int findMax(Node* root) {
    if (!root) return INT_MIN;
    while (root->right) root = root->right;
    return root->key;
}

// Inorder successor: smallest node > key
Node* inorderSuccessor(Node* root, int key) {
    Node* succ = nullptr;
    while (root) {
        if (root->key > key) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

// Inorder predecessor: largest node < key
Node* inorderPredecessor(Node* root, int key) {
    Node* pred = nullptr;
    while (root) {
        if (root->key < key) {
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        root = insertBST(root, x);
    }
    int keyToSearch, keySuccPred;
    cin >> keyToSearch;
    cin >> keySuccPred;

    cout << (searchRecursive(root, keyToSearch) ? "Found (recursive)\n" : "Not Found (recursive)\n");
    cout << (searchIterative(root, keyToSearch) ? "Found (iterative)\n" : "Not Found (iterative)\n");

    int mn = findMin(root);
    int mx = findMax(root);
    if (mn == INT_MIN) cout << "Tree empty\n"; else cout << "Min: " << mn << "\n";
    if (mx == INT_MIN) cout << "Tree empty\n"; else cout << "Max: " << mx << "\n";

    Node* succ = inorderSuccessor(root, keySuccPred);
    if (succ) cout << "Successor of " << keySuccPred << " is " << succ->key << "\n";
    else cout << "Successor of " << keySuccPred << " doesn't exist\n";

    Node* pred = inorderPredecessor(root, keySuccPred);
    if (pred) cout << "Predecessor of " << keySuccPred << " is " << pred->key << "\n";
    else cout << "Predecessor of " << keySuccPred << " doesn't exist\n";

    return 0;
}
