#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        front++;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }

    int getFrontIndex() {
        return front;
    }

    int getRearIndex() {
        return rear;
    }

    void reset() {
        front = 0;
        rear = -1;
    }
};

class StackTwoQueues {
    Queue q1, q2;

public:
    void push(int x) {
        q2.enqueue(x);

        while (!q1.isEmpty()) {
            q2.enqueue(q1.getFront());
            q1.dequeue();
        }

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
        q2.reset();
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        q1.dequeue();
    }

    int top() {
        if (q1.isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return q1.getFront();
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};

// Stack using One Queue
class StackOneQueue {
    Queue q;

public:
    void push(int x) {
        q.enqueue(x);

        // Rotate elements so that new element is at front
        int size = getSize();
        for (int i = 0; i < size - 1; i++) {
            int temp = q.getFront();
            q.dequeue();
            q.enqueue(temp);
        }
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        q.dequeue();
    }

    int top() {
        if (q.isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return q.getFront();
    }

    bool isEmpty() {
        return q.isEmpty();
    }

    int getSize() {
        return (q.isEmpty()) ? 0 : (q.getRearIndex() - q.getFrontIndex() + 1);
    }
};

int main() {
    cout << "Stack using Two Queues:" << endl;
    StackTwoQueues s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Top: " << s1.top() << endl; 
    s1.pop();
    cout << "Top after pop: " << s1.top() << endl; 

    cout << "\nStack using One Queue:" << endl;
    StackOneQueue s2;
    s2.push(100);
    s2.push(200);
    s2.push(300);
    cout << "Top: " << s2.top() << endl; 
    s2.pop();
    cout << "Top after pop: " << s2.top() << endl; 

    return 0;
}
