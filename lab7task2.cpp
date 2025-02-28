#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s; // Stack to store operators
    string postfix;

    for (char c : infix) {
        // If operand, add to postfix
        if (isalnum(c)) {
            postfix += c;
        } 
        // If '(', push to stack
        else if (c == '(') {
            s.push(c);
        } 
        // If ')', pop and add to postfix until '(' is found
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '('
        } 
        // If operator
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}
