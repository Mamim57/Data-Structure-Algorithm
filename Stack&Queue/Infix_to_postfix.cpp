#include<bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))    // If the character is an operand, add it to result
        {
            postfix += c;
        }
        else if (c == '(')      // If it's '(', push it to stack
        {
            s.push(c);
        }
        else if (c == ')')      // If it's ')', pop until '('
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // Pop '(' from stack
        }
        else      // If it's an operator
        {
            while (!s.empty() && precedence(s.top()) >= precedence(c))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);  // Push current operator to stack
        }
    }

    // Pop remaining operators from the stack
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;

    return 0;
}

