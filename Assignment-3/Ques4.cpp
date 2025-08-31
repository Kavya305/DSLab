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

int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infixToPostfix(string s)
{
    Stack st;
    string result = "";

    for (char c : s)
    {
        if (isalnum(c))
            result += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
            {
                result += st.pop();
            }
            st.pop(); // remove '('
        }
        else
        {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c))
            {
                result += st.pop();
            }
            st.push(c);
        }
    }
    while (!st.isEmpty())
        result += st.pop();

    return result;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
