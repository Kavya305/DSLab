// q3_bst_operations.cpp
#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);
    // duplicates ignored
    return root;
}

Node* findMinNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        // found
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        } else {
            Node* succ = findMinNode(root->right);
            root->key = succ->key;
            root->right = deleteNode(root->right, succ->key);
        }
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    return 1 + (l < r ? l : r);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        root = insertNode(root, x);
    }
    int delKey;
    cin >> delKey;
    root = deleteNode(root, delKey);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << "\n";

    cout << "Maximum depth: " << maxDepth(root) << "\n";
    cout << "Minimum depth: " << minDepth(root) << "\n";

    return 0;
}
