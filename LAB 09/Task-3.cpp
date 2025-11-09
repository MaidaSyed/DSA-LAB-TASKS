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

class AVL {
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

        // check unbalance cases
        if (balance > 1 && key < root->left->key)
            return rightRotate(root);

        if (balance < -1 && key > root->right->key)
            return leftRotate(root);

        if (balance > 1 && key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void printBalance(Node* root) {
        if (root != NULL) {
            printBalance(root->left);
            cout << "Node " << root->key << " -> Balance: " << getBalance(root) << endl;
            printBalance(root->right);
        }
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }
};

int main() {
    AVL tree;
    Node* root = NULL;
    int arr[] = {10, 5, 15, 3, 7};
    for (int i = 0; i < 5; i++)
        root = tree.insert(root, arr[i]);

    root = tree.insert(root, 12);

    cout << "Inorder after inserting 12: ";
    tree.inorder(root);
    cout << endl;

    cout << "\nBalance factors:\n";
    tree.printBalance(root);

    cout << "\nHeight of tree: " << tree.height(root) << endl;
    return 0;
}
