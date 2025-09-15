#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) { if (top < MAX - 1) arr[++top] = x; }
    int pop() { return (top >= 0) ? arr[top--] : -1; }
    bool isEmpty() { return top == -1; }
};

int evaluatePostfix(char postfix[]) {
    Stack s;
    int i = 0;
    while (postfix[i] != '\0') {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            s.push(c - '0');  
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
        i++;
    }
    return s.pop();
}

int main() {
    char postfix[MAX];
    cout << "Enter Postfix Expression: ";
    cin >> postfix;
    cout << "Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}
