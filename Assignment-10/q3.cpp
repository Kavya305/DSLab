// q3_frequency_hashmap.cpp
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

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* table[SIZE] = {nullptr};

    for (int i = 0; i < n; i++)
        insertOrCount(table, arr[i]);

    for (int i = 0; i < SIZE; i++) {
        Node* temp = table[i];
        while (temp) {
            cout << temp->key << " → " << temp->value << " times\n";
            temp = temp->next;
        }
    }

    return 0;
}
