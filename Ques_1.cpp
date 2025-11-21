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

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

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

    void insertBeforeAfter(int value, int target, bool insertAfter) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* newNode = new Node(value);
        if (!insertAfter && head->data == target) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp) {
            if (insertAfter && temp->data == target) { 
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            } 
            else if (!insertAfter && temp->next && temp->next->data == target) { 
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Target node not found.\n";
        delete newNode;
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecific(int target) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == target) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != target) temp = temp->next;
        if (!temp->next) {
            cout << "Node not found.\n";
            return;
        }
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    void searchNode(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found.\n";
    }

    void displayList() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, target;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target node value: ";
                cin >> target;
                list.insertBeforeAfter(value, target, false);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target node value: ";
                cin >> target;
                list.insertBeforeAfter(value, target, true);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> target;
                list.deleteSpecific(target);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.searchNode(value);
                break;
            case 9:
                list.displayList();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}