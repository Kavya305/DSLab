#include<iostream>
using namespace std;

#define MAX 100

class Queue{
    int arr[MAX];
    public:
    int front,rear;
    Queue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return rear == MAX -1;
    }

    bool isEmpty(){
        return front == -1;
    }

    void enqueue(int num){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
        } else {
            if(front == -1 && rear == -1){
            front++;
            rear++;
        } else{
            rear++;
        }
            arr[rear] = num;
        }
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Empty Queue"<<endl;
            return -1;
        } 
        int val = arr[front];
        if(front==rear){
            front = rear = -1;
        } else{
            front++;
        }
        return val;
    }

    void display(){
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        }else{
            for(int i = front; i<=rear; i++){
            cout<<arr[i]<<endl;
        }
        }
    }

    int peek(){
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main(){
    Queue q;
    int choice;
    while(true){
        cout<<"Enter \n1 for Enqueue\n2 for Dequeue\n3 to check Empty Queue\n4 to check Queue Overflow\n5 to Display\n6 to peek\n7 to exit."<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            int num;
            cout<<"Enter the number you want to add:";
            cin>>num;
            q.enqueue(num);
            break;
            case 2:
                cout<<q.dequeue()<<" is Dequeued."<<endl;
            break;
            case 3:
            cout<<q.isEmpty();
            break;
            case 4:
            cout<<q.isFull();
            break;
            case 5:
            q.display();
            break;
            case 6:
            cout<<q.peek();
            break;
            case 7:
            cout<<"Exiting ..."<<endl;
            return 0;
            break;
            default:
            cout<<"Invalid Argument! Try Again ."<<endl;
            break;
        }
    }
    return 0;
}