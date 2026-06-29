#include "infix_to_postfix.h"
#include <stack>
#include <cctype>

using namespace std;

// Function to return precedence of operators
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (char ch : infix)
    {
        // Ignore spaces
        if (ch == ' ')
            continue;

        // Operand
        if (isalnum(ch))
        {
            postfix += ch;
        }

        // Opening parenthesis
        else if (ch == '(')
        {
            s.push(ch);
        }

        // Closing parenthesis
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }

        // Operator
        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}
