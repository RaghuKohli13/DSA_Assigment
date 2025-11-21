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

    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == key) count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteOccurrences(int key) {
        while (head && head->data == key) {
            Node* del = head;
            head = head->next;
            delete del;
        }

        Node* current = head;
        while (current && current->next) {
            if (current->next->data == key) {
                Node* del = current->next;
                current->next = current->next->next;
                delete del;
            } else {
                current = current->next;
            }
        }
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
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Enter the key to count and delete: ";
    cin >> key;

    cout << "\nOriginal List: ";
    list.displayList();

    int count = list.countOccurrences(key);
    cout << "Occurrences of " << key << ": " << count << endl;

    list.deleteOccurrences(key);

    cout << "List after deleting all occurrences of " << key << ": ";
    list.displayList();

    return 0;
}
