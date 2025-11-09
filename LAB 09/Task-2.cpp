#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) {
        key = k;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
public:
    int height(Node* n) {
        if (n == NULL)
            return 0;
        return n->height;
    }

    int getBalance(Node* n) {
        if (n == NULL)
            return 0;
        return height(n->left) - height(n->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node* insert(Node* root, int key) {
        if (root == NULL)
            return new Node(key);
        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        else
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // LL
        if (balance > 1 && key < root->left->key)
            return rightRotate(root);

        // RR
        if (balance < -1 && key > root->right->key)
            return leftRotate(root);

        // LR
        if (balance > 1 && key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // RL
        if (balance < -1 && key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }
};

int main() {
    AVLTree tree;
    Node* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = tree.insert(root, arr[i]);

    root = tree.insert(root, 55); // inserting new node

    cout << "Before rotation (Inorder): ";
    tree.inorder(root);
    cout << endl;

    // Perform left rotation on root
    root = tree.leftRotate(root);

    cout << "After left rotation (Inorder): ";
    tree.inorder(root);
    cout << endl;

    return 0;
}
