// q4_first_non_repeating.cpp
#include <iostream>
using namespace std;

struct Node {
    int key, value;
    Node* next;
    Node(int k): key(k), value(1), next(nullptr) {}
};

const int SIZE = 10;

int hashFunction(int key) {
    return key % SIZE;
}

void insertOrCount(Node* table[], int key) {
    int idx = hashFunction(key);

    Node* temp = table[idx];
    while (temp) {
        if (temp->key == key) {
            temp->value++;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = new Node(key);
    newNode->next = table[idx];
    table[idx] = newNode;
}

int getCount(Node* table[], int key) {
    int idx = hashFunction(key);
    Node* temp = table[idx];
    while (temp) {
        if (temp->key == key) return temp->value;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* table[SIZE] = {nullptr};

    for (int i = 0; i < n; i++)
        insertOrCount(table, arr[i]);

    for (int i = 0; i < n; i++) {
        if (getCount(table, arr[i]) == 1) {
            cout << arr[i];
            return 0;
        }
    }

    cout << -1;
    return 0;
}
