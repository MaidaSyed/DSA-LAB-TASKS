#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int v)
    {
        val = v;
        left = right = nullptr;
    }
};

bool isBST(Node *root, int minVal, int maxVal)
{
    if(root == nullptr) return true;

    if(root->val <= minVal || root->val >= maxVal) return false;

    return isBST(root->left, minVal, root->val) && isBST(root->right, root->val, maxVal);
}

int main()
{
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);
    root1->right->right = new Node(5);

    cout << "Tree 1: ";
    if (isBST(root1, INT_MIN, INT_MAX))
        cout << "It is a BST" << endl;
    else
        cout << "Not a BST" << endl;

    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(20);
    root2->right->left = new Node(9); 
    root2->right->right = new Node(25);

    cout << "Tree 2: ";
    if (isBST(root2, INT_MIN, INT_MAX))
        cout << "It is a BST" << endl;
    else
        cout << "Not a BST" << endl;

}