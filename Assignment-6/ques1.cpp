#include <iostream>
using namespace std;

//DOUBLY LINKED LIST
class NodeDLL
{
    public:
    int data;
    NodeDLL *prev;
    NodeDLL *next;
    NodeDLL(int num)
    {
        data = num;
        prev = nullptr;
        next = nullptr;
    }
};

class Doublyll
{
    NodeDLL *head;
    public:
    Doublyll()
    {
        head = nullptr;
    }

    void isEmpty()
    {
        if (head == nullptr)
        {
            cout << "List is empty";
        }
    }

    // Insertion
    void insertAtBegin(int num)
    {
        NodeDLL *newNode = new NodeDLL(num);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int num){
        NodeDLL *newNode = new NodeDLL(num);
        if(!head){
            head = newNode;
        }else{
            NodeDLL* current = head;
            while(current->next){
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    void insertAfter(int value,int num){
        if(!head){
            cout<<"List is empty"<<endl;
            return;
        }else{
            NodeDLL* newNode = new NodeDLL(num);
            NodeDLL* current = head;
            while(current != nullptr && current->data != value){
                current = current->next;
            }
            if(current == nullptr){
                cout<<"value not found"<<endl;
                return;
            } else{
                newNode->prev = current;
                newNode->next = current->next;
                if(current->next != nullptr){
                    current->next->prev = newNode;
                }   
                current->next = newNode;
            }
        }
    }

    void insertBefore(int val, int num){
        if(!head){
            cout<<"List is empty!!"<<endl;
            return;
        }
        NodeDLL* curr = head;
        while(curr != nullptr && curr->data != val){
            curr = curr->next;
        }
        if(curr == nullptr){
            cout<<"Value not found!"<<endl;
            return;
        }
        NodeDLL* newNode = new NodeDLL(num);
        newNode->prev = curr->prev;
        newNode->next = curr;
        if(curr->prev!=nullptr){
            curr->prev->next = newNode;
        }else{
            head = newNode;
        }
        curr->prev = newNode;
    }

    //DELETION
    void deleteNode(int val){
        if(!head){
            cout<<"List is empty!!"<<endl;
            return;
        }
        NodeDLL* curr = head;
        while(curr!=nullptr && curr->data!=val){
            curr = curr->next;
        }
        if(curr == nullptr){
            cout<<"Node not found!!";
            return;
        }
        if(curr == head){
            head = head->next;
            if(head != nullptr){
                head->prev = nullptr;
            }
        } 
        else if(curr->next == nullptr){
            curr->prev->next =nullptr;
        }
        else {
            NodeDLL *cprev = curr->prev;
            NodeDLL *cnext = curr->next;
            cprev->next = curr->next;
            cnext->prev = curr->prev; 
        }
        delete curr;
        cout<<"Node deleted successfully!"<<endl;
    }

    //Search
    bool search(int val){
        if(!head){
            return false;
        }
        NodeDLL* curr = head;
        while(curr!=nullptr && curr->data!=val){
            curr = curr->next;
        }
        if(curr==nullptr){
            return false;
        }else{
            return true;
        }
    }
};

//CIRCULAR LINKED LIST
class NodeCLL
{
    public:
    int data;
    NodeCLL *next;
    NodeCLL(int num){
        data = num;
        next = nullptr;
    }
};

class CircularLL{
    NodeCLL* head;
    public:
    CircularLL(){
        head = nullptr;
    }
    //Deletion
    bool deleteNode(int val){
        if(!head){
            cout<<"List is empty"<<endl;
            return false;
        }
    }
    //Search
    bool search(int val){
        if (!head) {  // check for empty list
            cout << "List is empty!" << endl;
            return false;
        }
        NodeCLL* curr = head;
        do{
            if(curr->data == val){
                cout<<"Value found!"<<endl;
                return true;
            }
            curr = curr->next;
        }while(curr!=head);
        return false;
    }
};

int main()
{
    char choice;
    cout << "Press D for DLL \nPress C for CLL" << endl;
    cin >> choice;
    return 0;
}