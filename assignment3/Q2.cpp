#include<iostream>
#include<string>
using namespace std;

#define MAX 100

class Stack{
    char arr[MAX];
    int top;

    public:
        Stack(){
            top=-1;
        }

        bool isEmpty(){
            return (top == -1);
        }

        bool isFull(){
            return (top == MAX-1);
        }

        void push(char x){
            if (isFull()){
                cout<<"Stack overflow"<<endl;
            }
            else{
                arr[++top] = x;
            }
        }

        char pop(){
            if (isEmpty()){
                cout<<"Stack underflow"<<endl;
                return '\0';
            }
            else{
                return arr[top--];
            }
        }
};

int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;

    Stack s;

    for (int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    cout<<"Reversed string"<<endl;
    while (!s.isEmpty()){
        cout<<s.pop();
    }
    return 0;
}
