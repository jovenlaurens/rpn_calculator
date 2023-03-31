#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#include "dlist.h"
#include "stack.h"

using namespace std;

bool isOperator(string c) {
    // EFFECTS: returns true if c is an operator, false otherwise
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "n" || c == "d" || c == "r" || c == "p" || c == "c" || c == "a" || c == "q") && c.length() == 1;
}

bool isNumber(string c, int &n) {
    // EFFECTS: returns true if c is a number, false otherwise
    // MODIFIES: n
    // CHANGES: n to the number if c is a number
    int mult = 1;
    if (c[0] == '-') {
        c = c.substr(1);
        mult = -1;
    }
    if (c.length() < 1) {
        return false;
    }
    for (int i = 0; i < (int)c.length(); i++) {
        if (c[i] < '0' || c[i] > '9') {
            return false;
        } else {
            n = n * 10 + (c[i] - '0');
        }
    }
    n *= mult;
    return true;
}

bool isInput(string c, int n) {
    // EFFECTS: returns true if c is a valid input, false otherwise
    return isOperator(c) || isNumber(c, n);
}

int main() {
    string c;
    Stack stack, tempStack;
    int temp, temp2, n;
    while (cin >> c) {
        n = temp = temp2 = 0;
        if (isNumber(c, n)) {
            stack.push(new int(n));
        } else if (isOperator(c)) {
            char op = c[0];
            switch (op) {
                case '+':
                    if (stack.size() < 2) {
                        cout << "Not enough operands\n";
                        break;
                    }
                    stack.push(new int(*stack.pop() + *stack.pop()));
                    break;
                case '-':
                    if (stack.size() < 2) {
                        cout << "Not enough operands\n";
                        break;
                    }
                    temp = *stack.pop();
                    temp2 = *stack.pop();
                    stack.push(new int(temp2 - temp));
                    break;
                case '*':
                    if (stack.size() < 2) {
                        cout << "Not enough operands\n";
                        break;
                    }
                    stack.push(new int(*stack.pop() * *stack.pop()));
                    break;
                case '/':
                    if (stack.size() < 2) {
                        cout << "Not enough operands\n";
                        break;
                    }
                    temp = *stack.pop();
                    temp2 = *stack.pop();
                    if (temp == 0) {
                        cout << "Divide by zero\n";
                        stack.push(new int(temp2));
                        stack.push(new int(temp));
                        break;
                    }
                    stack.push(new int(temp2 / temp));
                    break;
                case 'n':
                    if (stack.size() < 1) {
                        cout << "Not enough operands\n";
                        break;
                    }
                    stack.push(new int(-*stack.pop()));
                    break;
                case 'd':
                    if (stack.size() < 1) {
                        cout << "Not enough operands\n";
                        break;
                    }
                    temp = *stack.pop();
                    stack.push(new int(temp));
                    stack.push(new int(temp));
                    break;
                case 'r':
                    if (stack.size() < 2) {
                        cout << "Not enough operands\n";
                        break;
                    }
                    temp = *stack.pop();
                    temp2 = *stack.pop();
                    stack.push(new int(temp));
                    stack.push(new int(temp2));
                    break;
                case 'p':
                    if (stack.size() < 1) {
                        cout << "Not enough operands\n";
                        break;
                    }
                    cout << *stack.top() << endl;
                    break;
                case 'c':
                    while (!stack.isEmpty()) {
                        stack.pop();
                    }
                    break;
                case 'a': {
                    if (stack.size() < 1) {
                        cout << "\n";
                        break;
                    }
                    while (!stack.isEmpty()) {
                        cout << *stack.top() << endl;
                        tempStack.push(stack.pop());
                    }
                    while (!tempStack.isEmpty()) {
                        stack.push(tempStack.pop());
                    }
                } break;
                case 'q':
                    return 0;
                default:
                    cout << "Bad input\n";
                    break;
            }
        } else {
            cout << "Bad input\n";
        }
    }
    return 0;
}