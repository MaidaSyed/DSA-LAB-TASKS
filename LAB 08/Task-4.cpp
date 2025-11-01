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

class BinarySearchTree
{
    Node *root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    Node *insertion(Node *n, int val)
    {
        if (n == nullptr)
        {
            return new Node(val);
        }
        else if (val < n->val)
        {
            n->left = insertion(n->left, val);
        }
        else if (val > n->val)
        {
            n->right = insertion(n->right, val);
        }
        return n;
    }
    void insert(int val) {   
        root = insertion(root, val);
    }

    Node *search(Node *n, int val)
    {
        if (n == nullptr || n->val == val)
            return n;
        if (val < n->val)
        {
            return search(n->left, val);
        }
        return search(n->right, val);
    }

    void Search(int v)
    {
        Node *n = search(root, v);
        if (n == nullptr)
        {
            cout << "Root not found. Insertion process.." << endl;
            root = insertion(root, v);
        }
        else
        {
            cout << "Value found" << endl;
        }
    }

    void inOrder(Node *n)
    {
        if (n == nullptr)
            return;
        inOrder(n->left);
        cout << n->val << " ";
        inOrder(n->right);
    }
    void display()
    {
        cout << "Inorder traversal: ";
        inOrder(root);
        cout << endl;
    }

    Node *getRoot()
    {
        return root;
    }
};

int main()
{
    BinarySearchTree b;

    Node *root = b.getRoot();
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(3);
    b.insert(7);
    b.insert(12);
    b.insert(18);

    cout << "Initial tree: "<<endl;
    b.display();
    cout << endl;

    cout << "Searching 7.." << endl;
    b.Search(7);

    cout << "\nSearching 20.." << endl;
    b.Search(20);

    cout << "\nTree after operations: ";
    b.inOrder(b.getRoot());
    cout << endl;

    return 0;
}