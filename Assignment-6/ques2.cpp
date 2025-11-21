#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};


Node* buildCircular(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* cur = head;

    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i]);
        cur->next = temp;
        cur = temp;
    }

    cur->next = head;  
    return head;
}

void displayCircular(Node* head) {
    if (!head) return;

    Node* temp = head;

    
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

  
    cout << head->data << " ";
}

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node* head = buildCircular(arr, n);

    displayCircular(head);

    return 0;
}
