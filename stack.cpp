#include "stack.h"

using namespace std;

int Stack::size() {
    // EFFECTS: returns the number of elements in the stack
    return numStack;
};

bool Stack::isEmpty() {
    // EFFECTS: returns true if list is empty, false otherwise
    return Dlist<int>::isEmpty();
};

void Stack::push(int *op) {
    // EFFECTS: inserts op at the front of the list
    numStack++;
    Dlist<int>::insertFront(op);
};

int *Stack::pop() {
    // EFFECTS: removes and returns first object from non-empty list
    numStack--;
    return Dlist<int>::removeFront();
};

int *Stack::top() {
    // EFFECTS: returns first object from non-empty list
    int *temp = Dlist<int>::removeFront();
    Dlist<int>::insertFront(temp);
    return temp;
};

Stack::~Stack() {
    // destructor
    while (!isEmpty()) {
        int *temp = pop();
        delete temp;
    }
};
