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

    Node* convertToAVL(Node* root) {
        if (root == NULL)
            return NULL;
        root->left = convertToAVL(root->left);
        root->right = convertToAVL(root->right);
        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
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

    Node* A = new Node(10);
    A->left = new Node(6);
    A->left->left = new Node(4);
    A->left->right = new Node(8);

    cout << "BST A (Inorder): ";
    tree.inorder(A);
    cout << endl;

    A = tree.convertToAVL(A);

    cout << "AVL from A (Inorder): ";
    tree.inorder(A);
    cout << endl;

    Node* B = new Node(10);
    B->right = new Node(16);
    B->right->left = new Node(12);
    B->right->right = new Node(18);

    cout << "\nBST B (Inorder): ";
    tree.inorder(B);
    cout << endl;

    B = tree.convertToAVL(B);

    cout << "AVL from B (Inorder): ";
    tree.inorder(B);
    cout << endl;

    return 0;
}
