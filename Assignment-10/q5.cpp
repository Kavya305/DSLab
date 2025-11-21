// q5_detect_loop.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

struct HashNode {
    Node* addr;
    HashNode* next;
    HashNode(Node* a): addr(a), next(nullptr) {}
};

const int SIZE = 10;

int hashFunction(Node* ptr) {
    return ((long long)ptr) % SIZE;
}

bool insertAndCheck(HashNode* table[], Node* ptr) {
    int idx = hashFunction(ptr);
    HashNode* temp = table[idx];

    while (temp) {
        if (temp->addr == ptr) return true;
        temp = temp->next;
    }

    HashNode* newNode = new HashNode(ptr);
    newNode->next = table[idx];
    table[idx] = newNode;
    return false;
}

bool detectLoop(Node* head) {
    HashNode* table[SIZE] = {nullptr};
    Node* temp = head;

    while (temp) {
        if (insertAndCheck(table, temp)) return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Create loop
    head->next->next->next->next = head->next; // loop to node 2

    cout << (detectLoop(head) ? "true" : "false");
}
