#include <iostream>
using namespace std;
#include <vector>

struct Node{
    int data;
    Node* next;
    Node (int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node (int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrToLL (vector<int>&arr){
    Node *head = new Node(arr[0]);
    Node *mover= head;
    for (int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

Node* reverseLL (Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    while (curr){
        Node* nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head=convertArrToLL(arr);
    Node* rev=reverseLL(head);
    Node *temp = rev;
    while (temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}