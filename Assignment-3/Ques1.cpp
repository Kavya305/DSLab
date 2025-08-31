#include <iostream>
using namespace std;

#define MAX 100

class Stack
{
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == MAX - 1);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack st;
    int choice, val;

    do
    {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            st.push(val);
            break;
        case 2:
            cout << "Popped: " << st.pop() << endl;
            break;
        case 3:
            cout << "Peek: " << st.peek() << endl;
            break;
        case 4:
            cout << (st.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
            break;
        case 5:
            cout << (st.isFull() ? "Stack is full\n" : "Stack is not full\n");
            break;
        case 6:
            st.display();
            break;
        }
    } while (choice != 7);

    return 0;
}
