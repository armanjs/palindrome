#include <iostream>
#include <string>
#include <fstream>
#include "stackArray.h"
#include "queueArray.h"
using namespace std;

bool isPalindrome(string word){

    stackArray stack (100);
    queueArray queue (100);

    for (int i = 0; i < word.length() ; ++i) {
        if (isalpha(word[i])){
            word[i] = tolower(word[i]);
            stack.push(word[i]);
            queue.addQueue(word[i]);
        }
    }

    while (!stack.isEmptyStack()){
        if (stack.top() == queue.front()) {
            stack.pop(); // delete the last
            queue.deleteQueue(); // delete the first
        }
        else { // if its not a palindrome
            break;
        }
    }
    // if went through the entire stack
    return stack.isEmptyStack();
}

int main() {

    /* for debugging
    stackArray stk1 (50);
    stk1.push('h');
    stk1.push('e');
    stk1.push('l');
    stk1.push('l');
    stk1.push('o');

    cout << stk1.top();
    stk1.pop();
    cout << stk1.top();
    stk1.pop();
    cout << stk1.top();
    stk1.pop();
    cout << stk1.top();
    stk1.pop();
    cout << stk1.top();
    stk1.pop();
    cout << stk1.top() << endl;

    queueArray que1(50);
    que1.addQueue('h');
    que1.addQueue('e');
    que1.addQueue('l');
    que1.addQueue('l');
    que1.addQueue('o');
    que1.deleteQueue(); // remove first element
    cout << que1.front() << " " << que1.back() << endl;
    */

    ifstream infile; // initialize in file steam
    string oneLine; // read one line into the variable
    infile.open("/Users/Arman/Desktop/CMPE126/Palindrome/palindrome.txt");

    if (infile.fail()){ // if failed to open
        cout << "file does not exist." << endl;
        exit(1);
    }
    while (!infile.eof()){ // read till the end of file
        getline(infile, oneLine);
        cout << isPalindrome(oneLine) << endl;
        cout << oneLine << endl;
    }

    infile.close();
    return 0;
}
