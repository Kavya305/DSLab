#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};


bool isCircular(Node* head) {
    if (head == nullptr)
        return true;   

    Node* temp = head->next;

    
    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }

    
    return (temp == head);
}

int main() {
  
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(5);

  
    head->next->next->next->next->next = head;

    if (isCircular(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}
