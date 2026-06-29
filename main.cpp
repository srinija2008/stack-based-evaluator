#include <iostream>
#include <cctype>
#include "stack.h"
#include "infix_to_postfix.h"

using namespace std;

int evaluatePostfix(string exp) {
    Stack s;

    for(char c : exp) {

        if(isdigit(c)) {
            s.push(c - '0');
        }
        else {
            int val1 = s.pop();
            int val2 = s.pop();

            switch(c) {
                case '+': s.push(val2 + val1); break;
                case '-': s.push(val2 - val1); break;
                case '*': s.push(val2 * val1); break;
                case '/': s.push(val2 / val1); break;
            }
        }
    }

    return s.pop();
}

bool isInfix(string exp)
{
    for(int i = 0; i < exp.length(); i++)
    {
        if(exp[i] == '(' || exp[i] == ')')
            return true;

        if(isalpha(exp[i]))
            return true;

        if(i > 0 && isdigit(exp[i]) &&
           (exp[i-1] == '+' || exp[i-1] == '-' ||
            exp[i-1] == '*' || exp[i-1] == '/'))
            return true;
    }

    return false;
}

bool hasVariables(string exp)
{
    for(char c : exp)
    {
        if(isalpha(c))
            return true;
    }

    return false;
}

int main()
{
    string exp;

    cout << "Enter expression: ";
    cin >> exp;

    if(isInfix(exp))
    {
        string postfix = infixToPostfix(exp);

        cout << "Postfix Expression = " << postfix << endl;

        if(!hasVariables(postfix))
        {
            cout << "Result = " << evaluatePostfix(postfix) << endl;
        }
    }
    else
    {
        cout << "Result = " << evaluatePostfix(exp) << endl;
    }

    return 0;
}
