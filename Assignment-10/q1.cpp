// q1_duplicates_hashset.cpp
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

const int SIZE = 10;

int hashFunction(int key) {
    return key % SIZE;
}

bool insertAndCheck(Node* table[], int key) {
    int idx = hashFunction(key);
    Node* temp = table[idx];

    while (temp) {
        if (temp->key == key) return true; // duplicate found
        temp = temp->next;
    }

    Node* newNode = new Node(key);
    newNode->next = table[idx];
    table[idx] = newNode;

    return false;
}

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* table[SIZE] = {nullptr};

    for (int i = 0; i < n; i++) {
        if (insertAndCheck(table, arr[i])) {
            cout << "true";
            return 0;
        }
    }

    cout << "false";
    return 0;
}
