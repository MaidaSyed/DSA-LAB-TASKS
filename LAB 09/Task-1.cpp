#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* left;
    Node* right;
    int height;
    Node(int r) {
        roll = r;
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

    Node* insert(Node* root, int roll) {
        if (root == NULL)
            return new Node(roll);

        if (roll < root->roll)
            root->left = insert(root->left, roll);
        else if (roll > root->roll)
            root->right = insert(root->right, roll);
        else
            return root; // duplicate roll, ignore

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // Left Left
        if (balance > 1 && roll < root->left->roll)
            return rightRotate(root);

        // Right Right
        if (balance < -1 && roll > root->right->roll)
            return leftRotate(root);

        // Left Right
        if (balance > 1 && roll > root->left->roll) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left
        if (balance < -1 && roll < root->right->roll) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->roll << " ";
            inorder(root->right);
        }
    }
};

int main() {
    AVL tree;
    Node* root = NULL;

    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);

    cout << "Before insertion (inorder): ";
    tree.inorder(root);
    cout << endl;

    // insert new student roll number 15
    root = tree.insert(root, 15);

    cout << "After insertion (inorder): ";
    tree.inorder(root);
    cout << endl;

    return 0;
}
