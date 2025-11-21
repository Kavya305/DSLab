#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v): data(v), prev(nullptr), next(nullptr) {}
};

int sizeDoubly(DNode* head) {
    int cnt = 0;
    DNode* cur = head;
    while (cur) {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}


DNode* buildDoubly(int arr[], int n) {
    if (n == 0) return nullptr;
    DNode* head = new DNode(arr[0]);
    DNode* tail = head;
    for (int i = 1; i < n; ++i) {
        DNode* node = new DNode(arr[i]);
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    return head;
}


struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};


Node* buildCircular(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        Node* node = new Node(arr[i]);
        tail->next = node;
        tail = node;
    }
    tail->next = head; 
    return head;
}


int sizeCircular(Node* head) {
    if (!head) return 0;
    int cnt = 1;
    Node* cur = head->next;
    while (cur != nullptr && cur != head) {
        ++cnt;
        cur = cur->next;
    }
    return cnt;
}

int main() {
    int n;
    cout << "Enter number of nodes for doubly linked list: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    DNode* dhead = buildDoubly(arr, n);
    cout << "Size of doubly linked list: " << sizeDoubly(dhead) << "\n";

    delete [] arr;

  
    int m;
    cout << "Enter number of nodes for circular linked list: ";
    cin >> m;
    int *brr = new int[m];
    for (int i = 0; i < m; ++i) cin >> brr[i];

    Node* chead = buildCircular(brr, m);
    cout << "Size of circular linked list: " << sizeCircular(chead) << "\n";

    delete [] brr;

    return 0;
}
