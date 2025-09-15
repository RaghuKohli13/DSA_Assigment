#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void push(char x) {
        if (!isFull()) {
            arr[++top] = x;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }

    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }

    bool isMatchingPair(char open, char close) {
        return ((open == '(' && close == ')') ||
                (open == '{' && close == '}') ||
                (open == '[' && close == ']'));
    }

    bool isBalanced(string expr) {
        Stack s;  
        for (int i = 0; i < expr.length(); i++) {
            char ch = expr[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                s.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (s.isEmpty()) return false;
                char topChar = s.pop();
                if (!isMatchingPair(topChar, ch)) return false;
            }
        }
        return s.isEmpty();
    }
};

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    Stack s;  
    if (s.isBalanced(expr)) {
        cout << "Balanced expression" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    return 0;
}
