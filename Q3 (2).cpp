#include <iostream>
#include <algorithm>
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

    Node* findMin(Node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == NULL) return root;
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int minDepth(Node* root) {
        if (root == NULL) return 0;
        if (!root->left && !root->right) return 1;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
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

    root = tree.deleteNode(root, 70);
    cout << "After Deletion: ";
    tree.inorder(root);
    cout << endl;

    cout << "Maximum Depth: " << tree.maxDepth(root) << endl;
    cout << "Minimum Depth: " << tree.minDepth(root) << endl;

    return 0;
}
