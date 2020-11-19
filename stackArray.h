//
// Created by Arman Sadeghi on 11/16/20.
//

#ifndef PALINDROME_STACKARRAY_H
#define PALINDROME_STACKARRAY_H
#include <iostream>

using namespace std;

class stackArray {
public:
    stackArray(int stackSize = 50);
    ~stackArray();
    void push(char);
    void pop();
    char top();
    bool isFullStack();
    bool isEmptyStack();

private:
    int maxStackSize; // maxStackSize of the list
    int stackTop; // number of elements in stack
    char* list; // a dynamic array of chars

};

stackArray::stackArray(int stackSize) {
    maxStackSize = stackSize;
    stackTop = 0;
    list = new char[stackSize];
}

stackArray::~stackArray() {
    delete list;
}

void stackArray::push(char item) {
    // check if stack is full or not
    if (!isFullStack()){
        list[stackTop] = item;
        stackTop++; // increment the number of elements
    }
    else {
        cout << "cannot add to a full stack." << endl;
    }
}

void stackArray::pop() {
    //cout << list[stackTop - 1];
    if (stackTop != 0){
        stackTop--;
    }
    else {
        cout << "List is empty." << endl;
    }
}

char stackArray::top() {
    return list[stackTop - 1];
}

bool stackArray::isFullStack() {
    return (stackTop == maxStackSize);
}

bool stackArray::isEmptyStack() {
    return (stackTop == 0);
}
#endif //PALINDROME_STACKARRAY_H
