// q2_common_elements.cpp
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
    Node(int k): key(k), next(nullptr) {}
};

const int SIZE = 10;

int hashFunction(int key) {
    return key % SIZE;
}

void insert(Node* table[], int key) {
    int idx = hashFunction(key);
    Node* newNode = new Node(key);
    newNode->next = table[idx];
    table[idx] = newNode;
}

bool search(Node* table[], int key) {
    int idx = hashFunction(key);
    Node* temp = table[idx];
    while (temp) {
        if (temp->key == key) return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    int n1, n2;
    cin >> n1;
    int A[100];
    for (int i = 0; i < n1; i++) cin >> A[i];

    cin >> n2;
    int B[100];
    for (int i = 0; i < n2; i++) cin >> B[i];

    Node* table[SIZE] = {nullptr};
    for (int i = 0; i < n1; i++)
        insert(table, A[i]);

    for (int i = 0; i < n2; i++)
        if (search(table, B[i]))
            cout << B[i] << " ";

    return 0;
}
