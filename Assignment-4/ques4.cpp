#include <iostream>
using namespace std;

#define MAX 100

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
        if (isEmpty()) {
            return;
        }
        front++;
    }

    char getFront() {
        if (isEmpty()) return '\0';
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }

    void reset() {
        front = 0;
        rear = -1;
    }
};

void firstNonRepeating(string str) {
    Queue q;
    int freq[26] = {0}; 
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        freq[ch - 'a']++;

        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.getFront() - 'a'] > 1) {
            q.dequeue();
        }

        if (q.isEmpty())
            cout << -1 << " ";
        else
            cout << q.getFront() << " ";
    }
    cout << endl;
}

int main() {
    string input = "aabc";
    cout << "Input: " << input << endl;
    cout << "Output: ";
    firstNonRepeating(input);
    return 0;
}


