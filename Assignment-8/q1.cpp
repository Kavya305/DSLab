// q1_traversals.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Build binary tree from level-order array where -1 denotes null.
// Indexing like binary heap: left = 2*i+1, right = 2*i+2
Node* buildFromLevelOrder(int arr[], int n, int i) {
    if (i >= n) return nullptr;
    if (arr[i] == -1) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = buildFromLevelOrder(arr, n, 2*i + 1);
    root->right = buildFromLevelOrder(arr, n, 2*i + 2);
    return root;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    Node* root = buildFromLevelOrder(arr, n, 0);

    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\n";

    delete [] arr;
    return 0;
}
