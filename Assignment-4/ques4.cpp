#include <iostream>
using namespace std;

#define MAX 1000  

class Queue {
    char arr[MAX];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(char x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty()) return;
        front++;
    }

    char getFront() {
        if (isEmpty()) return '\0';
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};


void firstNonRepeating(char str[], int n) {
    int freq[256] = {0};  
    Queue q;

    for (int i = 0; i < n; i++) {
        char ch = str[i];
        if (ch == ' ') continue;  

        freq[(int)ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[(int)q.getFront()] > 1) {
            q.dequeue();
        }

        if (!q.isEmpty())
            cout << q.getFront() << " ";
        else
            cout << -1 << " ";
    }
    cout << endl;
}

int main() {
    char input[] = {'a', ' ', 'a', ' ', 'b', ' ', 'c'};
    int n = sizeof(input) / sizeof(input[0]);

    cout << "Input: ";
    for (int i = 0; i < n; i++) cout << input[i];
    cout << endl;

    cout << "Output: ";
    firstNonRepeating(input, n);

    return 0;
}
