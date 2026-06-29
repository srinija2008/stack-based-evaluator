#include <iostream>
#include <cmath>
using namespace std;

#define max 100

// Stack for Infix to Postfix
char a[max];
int top = -1;

void push(char c) {
    a[++top] = c;
}

char pop() {
    return a[top--];
}

char peek() {
    return a[top];
}

int isempty() {
    return top == -1;
}

// Stack for Postfix Evaluation
class post {
    int arr[max], top1;

public:
    post() {
        top1 = -1;
    }

    void push1(int v) {
        arr[++top1] = v;
    }

    int pop1() {
        return arr[top1--];
    }

    bool isempty1() {
        return top1 == -1;
    }
};

int main() {

    // ---------------- INFIX TO POSTFIX ----------------

    char infix[max], postfix[max];
    int j = 0;

    cout << "Enter the infix expression:" << endl;
    cin >> infix;

    for (int i = 0; infix[i] != '\0'; i++) {

        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        }

        else if (c == '(') {
            push(c);
        }

        else if (c == ')') {

            while (!isempty() && peek() != '(') {
                postfix[j++] = pop();
            }

            pop();
        }

        else {

            int cp = (c == '^') ? 3 :
                     (c == '*' || c == '/') ? 2 : 1;

            while (!isempty() && peek() != '(') {

                char t = peek();

                int tp = (t == '^') ? 3 :
                         (t == '*' || t == '/') ? 2 :
                         (t == '+' || t == '-') ? 1 : 0;

                if ((c == '^' && tp > cp) ||
                    (c != '^' && tp >= cp)) {

                    postfix[j++] = pop();
                }

                else {
                    break;
                }
            }

            push(c);
        }
    }

    while (!isempty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    // ---------------- POSTFIX EVALUATION ----------------

    post p;
    int x, y;

    for (int i = 0; postfix[i] != '\0'; i++) {

        char c = postfix[i];

        if (c >= '0' && c <= '9') {

            p.push1(c - '0');
        }

        else if (c == '+' || c == '-' || c == '*' ||
                 c == '/' || c == '^') {

            y = p.pop1();
            x = p.pop1();

            if (c == '+') {
                p.push1(x + y);
            }

            else if (c == '-') {
                p.push1(x - y);
            }

            else if (c == '*') {
                p.push1(x * y);
            }

            else if (c == '/') {

                if (y == 0) {
                    cout << "Infinite as it is divided by 0" << endl;
                    return 1;
                }

                p.push1(x / y);
            }

            else if (c == '^') {
                p.push1((int)pow(x, y));
            }

            else {
                cout << "Invalid characters" << endl;
                return 1;
            }
        }
    }

    cout << "Result: " << p.pop1() << endl;

    return 0;
}
