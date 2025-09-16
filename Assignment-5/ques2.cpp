#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
    //Insert
    void insert(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* current = head;
        while(current->next!=nullptr){
            current = current->next;
        }
        current->next = newNode;
    }

    //Display
    void display(){
        if(head==nullptr){
            cout<<"Empty Linked List!";
            return;
        }
        Node* current = head;
        while(current != nullptr){
            cout<<current->data<<"->";
            current = current->next;
        }
    }

    //Count
    int count(int key){
        if(head==nullptr){
            cout<<"Empty Linked List!";
            return;
        }
        int count = 0;
        Node* current = head;
        while(current!=nullptr){
            if(current->data == key){
                count++;
            }
            current = current->next;
        }
        return count;
    }

    void deleteKeys(int key){
        if(head==nullptr){
            cout<<"Empty Linked List!";
            return;
        }
        while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;  
        }

        Node* current = head;
        Node* prev = nullptr;
        while(current!=nullptr){
            if(current->data == key){
            prev->next = current->next;
            delete current;
            current = prev->next;
            }else{
                prev = current;
                current = current->next;
            }
        }
    }
};

int main(){
    LinkedList list;
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insert(val);
    }

    cout << "Linked List before deletion: ";
    list.display();

    cout << "Enter key to count and delete: ";
    cin >> key;

    int count = list.count(key);
    cout << "Occurrences of " << key << ": " << count << endl;

    list.deleteKeys(key);

    cout << "Linked List after deletion: ";
    list.display();
    return 0;

}
