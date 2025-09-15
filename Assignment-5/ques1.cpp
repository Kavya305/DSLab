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

//Search
    void searchNode(int value){
        int position = 1; 
        Node* current = head;
        if(head==nullptr){
            cout<<"Empty Linked List!"<<endl;
            return;
        }
        while(current!=nullptr && current->data != value){
            current = current->next;
            position++;
        }
        if(current==nullptr){
            cout<<"Value not found!"<<endl;
        }else if(position == 1){
            cout<<"Value found at head!"<<endl;
        }else{
            cout<<"Value found at "<<position<<"position from head"<<endl;
        }
    }
//Insertion functions
    //Beginning
    void insertAtBeginning(int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    }
    //End
    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if(head==nullptr){
            head = newNode;
        }else{
            Node* current = head;
            while(current->next!=nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
    }
    //After
    void insertAfter(int value,int key){
        Node* newNode = new Node(value);
        Node* current = head;
        if(head==nullptr){
            head = newNode;
            return;
        }
        while(current!=nullptr && current->data!=key){
            current=current->next;
        }
        if(current==nullptr){
            cout<<"Value not found!"<<endl;
        }else{
            newNode->next = current->next;
            current->next = newNode;
        }
    }

//Deletion Functions
    //Beginnning
    void deleteAtBeginning(){
        if(head == nullptr){
            cout<<"Empty Linked List!";
            return;
        } 
        Node* current = head;
        head = head->next;
        delete current;
    }
    //End
    void deleteAtEnd(){
        if(head == nullptr){
            cout<<"Empty Linked List!";
            return;
        } else if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while(current->next->next != nullptr){
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    //Specific Node
    void deleteSpecificNode(int value){
        if(head==nullptr){
            cout<<"Empty linked list!"<<endl;
            return;
        }
        Node* current = head;
        Node* prev = nullptr;
        while(current!=nullptr && current->data != value){
            prev = current;
            current = current->next;
        }
        if(current==nullptr){
            cout<<"Value not found!"<<endl;
            return;
        }

        if(current == head){
            head = head->next;
        } else if(current->next == nullptr){
            prev->next == nullptr;
        }else{
            prev->next = current->next;
        }
        delete current;
    }

//Display
    void display(){
        Node* current = head;
        while(current!=nullptr){
            cout<<current->data<<",";
            current = current->next;
        }
    }
};

int main(){
    int choice, value, key;
    LinkedList L;

    while (choice != 0){
        cout << "\n\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search a Node\n";
        cout << "8. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                L.insertAtBeginning(value);
                cout << value << " inserted at beginning.\n";
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                L.insertAtEnd(value);
                cout << value << " inserted at end.\n";
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter the node value after which to insert: ";
                cin >> key;
                L.insertAfter(value, key);
                break;

            case 4:
                L.deleteAtBeginning();
                cout << "Deleted node from beginning.\n";
                break;

            case 5:
                L.deleteAtEnd();
                cout << "Deleted node from end.\n";
                break;

            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                L.deleteSpecificNode(value);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                L.searchNode(value);
                break;

            case 8:
                cout << "Linked List: ";
                L.display();
                cout << endl;
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } 

    return 0;
}
  
