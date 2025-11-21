#include <iostream>
using namespace std;

// ===================== DOUBLY LINKED LIST =====================
class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        cout << val << " inserted at beginning.\n";
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (head == NULL) {
            head = newNode;
            cout << val << " inserted as head.\n";
            return;
        }
        DNode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        cout << val << " inserted at end.\n";
    }

    void insertBeforeAfter(int key, int val, string pos) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        DNode* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        DNode* newNode = new DNode(val);
        if (pos == "before") {
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev)
                temp->prev->next = newNode;
            else
                head = newNode;
            temp->prev = newNode;
            cout << val << " inserted before " << key << ".\n";
        } else if (pos == "after") {
            newNode->prev = temp;
            newNode->next = temp->next;
            if (temp->next)
                temp->next->prev = newNode;
            temp->next = newNode;
            cout << val << " inserted after " << key << ".\n";
        }
    }

    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        DNode* temp = head;
        while (temp != NULL && temp->data != val)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node " << val << " not found.\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        cout << "Node " << val << " deleted.\n";
        delete temp;
    }

    void search(int val) {
        DNode* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << val << " not found.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        DNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ===================== CIRCULAR LINKED LIST =====================
class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    CNode* head;
public:
    CircularLinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        CNode* newNode = new CNode(val);
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            CNode* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << val << " inserted at beginning.\n";
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            CNode* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << val << " inserted at end.\n";
    }

    void insertBeforeAfter(int key, int val, string pos) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode(val);
                if (pos == "after") {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    cout << val << " inserted after " << key << ".\n";
                    return;
                } else if (pos == "before") {
                    CNode* prev = head;
                    while (prev->next != temp)
                        prev = prev->next;
                    newNode->next = temp;
                    prev->next = newNode;
                    if (temp == head)
                        head = newNode;
                    cout << val << " inserted before " << key << ".\n";
                    return;
                }
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        CNode *temp = head, *prev = NULL;
        do {
            if (temp->data == val) {
                if (temp == head) {
                    CNode* last = head;
                    while (last->next != head)
                        last = last->next;
                    if (head->next == head) {
                        delete head;
                        head = NULL;
                    } else {
                        head = head->next;
                        last->next = head;
                        delete temp;
                    }
                } else {
                    prev->next = temp->next;
                    delete temp;
                }
                cout << "Node " << val << " deleted.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << val << " not found.\n";
    }

    void search(int val) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << val << " not found.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data;
            if (temp->next != head) cout << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << " (circular)\n";
    }
};

// ===================== MAIN MENU =====================
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, listType, val, key;
    string pos;

    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> listType;

        if (listType == 3) break;

        do {
            cout << "\n--- Operations Menu ---\n";
            cout << "1. Insert at Beginning\n";
            cout << "2. Insert at End\n";
            cout << "3. Insert Before/After a Node\n";
            cout << "4. Delete a Node\n";
            cout << "5. Search a Node\n";
            cout << "6. Display List\n";
            cout << "7. Back to Main Menu\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (listType == 1) { // Doubly Linked List
                switch (choice) {
                    case 1: cout << "Enter value: "; cin >> val; dll.insertAtBeginning(val); break;
                    case 2: cout << "Enter value: "; cin >> val; dll.insertAtEnd(val); break;
                    case 3: cout << "Enter key, value, and 'before/after': "; cin >> key >> val >> pos; dll.insertBeforeAfter(key, val, pos); break;
                    case 4: cout << "Enter node value to delete: "; cin >> val; dll.deleteNode(val); break;
                    case 5: cout << "Enter node value to search: "; cin >> val; dll.search(val); break;
                    case 6: dll.display(); break;
                }
            } 
            else if (listType == 2) { // Circular Linked List
                switch (choice) {
                    case 1: cout << "Enter value: "; cin >> val; cll.insertAtBeginning(val); break;
                    case 2: cout << "Enter value: "; cin >> val; cll.insertAtEnd(val); break;
                    case 3: cout << "Enter key, value, and 'before/after': "; cin >> key >> val >> pos; cll.insertBeforeAfter(key, val, pos); break;
                    case 4: cout << "Enter node value to delete: "; cin >> val; cll.deleteNode(val); break;
                    case 5: cout << "Enter node value to search: "; cin >> val; cll.search(val); break;
                    case 6: cll.display(); break;
                }
            }
        } while (choice != 7);

    } while (listType != 3);

    cout << "Exiting program...\n";
    return 0;
}
