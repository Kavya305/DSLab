// q4_is_bst.cpp
#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};

Node* buildFromLevelOrder(int arr[], int n, int i) {
    if (i >= n) return nullptr;
    if (arr[i] == -1) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = buildFromLevelOrder(arr, n, 2*i + 1);
    root->right = buildFromLevelOrder(arr, n, 2*i + 2);
    return root;
}

bool isBSTUtil(Node* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (node->data <= minVal || node->data >= maxVal) return false;
    return isBSTUtil(node->left, minVal, node->data) &&
           isBSTUtil(node->right, node->data, maxVal);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    Node* root = buildFromLevelOrder(arr, n, 0);
    bool ok = isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    cout << (ok ? "YES\n" : "NO\n");

    delete [] arr;
    return 0;
}
