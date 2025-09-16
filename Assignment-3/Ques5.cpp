#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack
{
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x)
    {
        if (top != MAX - 1)
            arr[++top] = x;
    }

    bool isEmpty() {
        return top == -1;
    }

    int pop(){
        int value;
        if(isEmpty()){
            cout<<"Empty Stack!"<<endl;
        } else {
            value = arr[top];
            top--;
        }
        return value;
    }
    
};

int evaluatePostfix(string exp)
{
    Stack s;
    for (char c : exp)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else
        {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (c)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            }
        }
    }
    return s.pop();
}

int main()
{
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}

