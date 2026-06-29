#ifndef STACK_H
#define STACK_H

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack();
    void push(int x);
    int pop();
    bool isEmpty();
};

