//
// Created by Arman Sadeghi on 11/18/20.
//

#ifndef PALINDROME_QUEUEARRAY_H
#define PALINDROME_QUEUEARRAY_H
#include <iostream>
using namespace std;

class queueArray{

public:
    queueArray(int queueSize = 100); // constructor
    ~queueArray(); // destructor
    char front(); // return the first element
    char back(); // return the last element
    void addQueue(char c); // add element to queue
    void deleteQueue(); // remove first element from queue
    bool isEmptyQueue();
    bool isFullQueue();

private:
    int maxQueueSize; // maximum number of elements
    int count; // current number of elements
    int queueFront; // pointing to the front
    int queueRear; // pointing to the rear
    char *list; // pointer to array that holds queue elements

};

bool queueArray::isEmptyQueue() {
    return (count == 0);
}

bool queueArray::isFullQueue() {
    return (count == maxQueueSize);
}

char queueArray::front() {
    return list[queueFront];
}

char queueArray::back() {
    return list[queueRear];
}

void queueArray::addQueue(char c) {
    if (!isFullQueue()){
        queueRear = (queueRear + 1) % maxQueueSize;
        count++;
        list[queueRear] = c;
    }
    else {
        cout << "cannot add to a full queue." << endl;
    }

}

void queueArray::deleteQueue() {
    if (!isEmptyQueue()){
        count--;
        queueFront = (queueFront + 1) % maxQueueSize;
    }
    else {
        cout << "cannot remove from an empty queue." << endl;
    }
}

queueArray::queueArray(int queueSize) {
    maxQueueSize = queueSize;
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
    list = new char [maxQueueSize];
}

queueArray::~queueArray() {
    delete [] list;
}

#endif //PALINDROME_QUEUEARRAY_H
