// q6_tree_duplicates.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

struct HashNode {
    int key;
    HashNode* next;
    HashNode(int k): key(k), next(nullptr) {}
};

const int SIZE = 10;

int hashFunction(int key) {
    return key % SIZE;
}

bool insertAndCheck(HashNode* table[], int key) {
    int idx = hashFunction(key);
    HashNode* temp = table[idx];

    while (temp) {
        if (temp->key == key) return true;
        temp = temp->next;
    }

    HashNode* newNode = new HashNode(key);
    newNode->next = table[idx];
    table[idx] = newNode;
    return false;
}

bool checkDuplicates(Node* root, HashNode* table[]) {
    if (!root) return false;

    if (insertAndCheck(table, root->data)) return true;

    return checkDuplicates(root->left, table) ||
           checkDuplicates(root->right, table);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(3); // duplicate

    HashNode* table[SIZE] = {nullptr};

    if (checkDuplicates(root, table))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
