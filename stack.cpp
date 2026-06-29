#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack() {
    top = -1;
}

void Stack::push(int x) {
    if(top >= MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    arr[++top] = x;
}

int Stack::pop() {
    if(top < 0) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return arr[top--];
}

bool Stack::isEmpty() {
    return top < 0;
}
