#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack
{
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x)
    {
        if (top != MAX - 1)
            top++;
            arr[top] = x;
    }

    bool isEmpty() {
        return top == -1;
    }

    int pop(){
        int value;
        if(isEmpty()){
            cout<<"Stack Underflow!"<<endl;
        } else {
            value = arr[top];
            top--;
        }
        return value;
    }
};

bool isBalanced(string expr)
{
    Stack s;
    for (char c : expr)
    {
        if (c == '(' || c == '[' || c == '{')
            s.push(c);
        else if (c == ')' || c == ']' || c == '}')
        {
            if (s.isEmpty())
                return false;
            char top = s.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;
        }
    }
    return s.isEmpty();
}

int main()
{
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}

