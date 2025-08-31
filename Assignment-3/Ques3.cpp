#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack
{
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }
    void push(char c)
    {
        if (top != MAX - 1)
            arr[++top] = c;
    }
    char pop() { return (top != -1) ? arr[top--] : '\0'; }
    char peek() { return (top != -1) ? arr[top] : '\0'; }
    bool isEmpty() { return (top == -1); }
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
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
