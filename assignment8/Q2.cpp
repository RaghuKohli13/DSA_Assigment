#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:
    Node* insert(Node* root, int val) {
        if (root == NULL) return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);
        return root;
    }

    Node* searchRecursive(Node* root, int key) {
        if (root == NULL || root->data == key) return root;
        if (key < root->data)
            return searchRecursive(root->left, key);
        else
            return searchRecursive(root->right, key);
    }

    Node* searchIterative(Node* root, int key) {
        while (root != NULL) {
            if (key == root->data) return root;
            else if (key < root->data) root = root->left;
            else root = root->right;
        }
        return NULL;
    }

    Node* findMin(Node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    Node* findMax(Node* root) {
        while (root && root->right != NULL)
            root = root->right;
        return root;
    }

    Node* inorderSuccessor(Node* root, Node* target) {
        if (target->right != NULL)
            return findMin(target->right);
        Node* succ = NULL;
        while (root != NULL) {
            if (target->data < root->data) {
                succ = root;
                root = root->left;
            } else if (target->data > root->data) {
                root = root->right;
            } else break;
        }
        return succ;
    }

    Node* inorderPredecessor(Node* root, Node* target) {
        if (target->left != NULL)
            return findMax(target->left);
        Node* pred = NULL;
        while (root != NULL) {
            if (target->data > root->data) {
                pred = root;
                root = root->right;
            } else if (target->data < root->data) {
                root = root->left;
            } else break;
        }
        return pred;
    }

    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    BST tree;
    Node* root = NULL;
    root = tree.insert(root, 50);
    tree.insert(root, 30);
    tree.insert(root, 70);
    tree.insert(root, 20);
    tree.insert(root, 40);
    tree.insert(root, 60);
    tree.insert(root, 80);

    cout << "Inorder Traversal: ";
    tree.inorder(root);
    cout << endl;

    int key = 40;
    Node* res1 = tree.searchRecursive(root, key);
    cout << "Recursive Search for " << key << ": " << (res1 ? "Found" : "Not Found") << endl;

    Node* res2 = tree.searchIterative(root, key);
    cout << "Iterative Search for " << key << ": " << (res2 ? "Found" : "Not Found") << endl;

    cout << "Minimum Element: " << tree.findMin(root)->data << endl;
    cout << "Maximum Element: " << tree.findMax(root)->data << endl;

    Node* target = tree.searchIterative(root, 50);
    Node* succ = tree.inorderSuccessor(root, target);
    Node* pred = tree.inorderPredecessor(root, target);

    cout << "Inorder Successor of 50: " << (succ ? to_string(succ->data) : "None") << endl;
    cout << "Inorder Predecessor of 50: " << (pred ? to_string(pred->data) : "None") << endl;

    return 0;
}
