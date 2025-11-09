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
        return root;
    }

    void inorder(Node* root, int& count, int k, int& ans, bool smallest) {
        if (root == NULL) return;
        if (smallest) {
            inorder(root->left, count, k, ans, smallest);
            count++;
            if (count == k) ans = root->key;
            inorder(root->right, count, k, ans, smallest);
        } else {
            inorder(root->right, count, k, ans, smallest);
            count++;
            if (count == k) ans = root->key;
            inorder(root->left, count, k, ans, smallest);
        }
    }

    int kthSmallest(Node* root, int k) {
        int count = 0, ans = -1;
        inorder(root, count, k, ans, true);
        return ans;
    }

    int kthLargest(Node* root, int k) {
        int count = 0, ans = -1;
        inorder(root, count, k, ans, false);
        return ans;
    }
};

int main() {
    AVL tree;
    Node* root = NULL;
    int arr[] = {20, 10, 30, 5, 15, 25, 35};
    for (int i = 0; i < 7; i++)
        root = tree.insert(root, arr[i]);

    int k = 2;
    cout << "2nd Smallest: " << tree.kthSmallest(root, k) << endl;
    cout << "2nd Largest: " << tree.kthLargest(root, k) << endl;

    cout << "\nLeft Subtree Height: " << tree.height(root->left);
    cout << "\nRight Subtree Height: " << tree.height(root->right) << endl;

    return 0;
}
