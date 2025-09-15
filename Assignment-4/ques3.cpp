#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) { 
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        return val;
    }

    int size() {
        if (isEmpty()) return 0;
        if (rear >= front) return rear - front + 1;
        return MAX - (front - rear - 1);
    }
};

void interleaveQueue(Queue &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue length must be even\n";
        return;
    }

    int half = n / 2;
    Queue q1;

    for (int i = 0; i < half; i++) {
        q1.enqueue(q.dequeue());
    }

    while (!q1.isEmpty()) {
        q.enqueue(q1.dequeue());  
        q.enqueue(q.dequeue());   
    }
}

int main() {
    Queue q;
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}
