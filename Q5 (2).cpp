#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void makeCircular() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head;  // last node points to head
    }

    bool isCircular() {
        if (head == NULL) return true;
        Node* temp = head->next;
        while (temp != NULL && temp != head)
            temp = temp->next;
        return (temp == head);
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Initially: ";
    if (list.isCircular())
        cout << "Circular Linked List" << endl;
    else
        cout << "Not Circular Linked List" << endl;

    list.makeCircular();  // make it circular manually

    cout << "After making circular: ";
    if (list.isCircular())
        cout << "Circular Linked List" << endl;
    else
        cout << "Not Circular Linked List" << endl;

    return 0;
}
