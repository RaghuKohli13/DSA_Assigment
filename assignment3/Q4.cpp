#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) { if (top < MAX - 1) arr[++top] = c; }
    char pop() { return (top >= 0) ? arr[top--] : -1; }
    char peek() { return (top >= 0) ? arr[top] : -1; }
    bool isEmpty() { return top == -1; }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            postfix[j++] = c;
        else if (c == '(')
            s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix[j++] = s.pop();
            s.pop();
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
                postfix[j++] = s.pop();
            s.push(c);
        }
        i++;
    }
    while (!s.isEmpty())
        postfix[j++] = s.pop();
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter Infix Expression: ";
    cin >> infix;
    infixToPostfix(infix, postfix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}
