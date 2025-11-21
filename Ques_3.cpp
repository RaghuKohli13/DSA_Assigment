#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    int findMiddle() {
        if (!head) {
            cout << "List is empty.\n";
            return -1; 
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;         
            fast = fast->next->next;  
        }
        return slow->data;
    }

    void displayList() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "\nLinked List: ";
    list.displayList();

    int middle = list.findMiddle();
    if (middle != -1)
        cout << "Middle element: " << middle << endl;

    return 0;
}