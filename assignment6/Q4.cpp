#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = tail = NULL;
    }

    void insertAtEnd(char val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    bool isPalindrome() {
        if (head == NULL) return true;
        Node* left = head;
        Node* right = tail;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Example input: A <-> B <-> C <-> B <-> A
    dll.insertAtEnd('A');
    dll.insertAtEnd('B');
    dll.insertAtEnd('C');
    dll.insertAtEnd('B');
    dll.insertAtEnd('A');

    cout << "Linked List: ";
    dll.display();

    if (dll.isPalindrome())
        cout << "The Doubly Linked List is a Palindrome." << endl;
    else
        cout << "The Doubly Linked List is NOT a Palindrome." << endl;

    return 0;
}
