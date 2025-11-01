#include <iostream>
using namespace std;

struct Node
{
    int ID;
    int quantity;
    Node *left;
    Node *right;
    Node(int id, int q)
    {
        ID = id;
        quantity = q;
        left = right = nullptr;
    }
    void update(int q)
    {
        quantity = q;
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

    Node *insertion(Node *n, int id, int q)
    {
        if (n == nullptr)
        {
            return new Node(id, q);
        }
        else if (id < n->ID)
        {
            n->left = insertion(n->left, id, q);
        }
        else if (id > n->ID)
        {
            n->right = insertion(n->right, id, q);
        }
        return n;
    }
    void insert(int id, int q)
    {
        root = insertion(root, id, q);
    }

    Node *Search(Node *root, int id)
    {
        if (root == nullptr || root->ID == id)
            return root;
        if (id < root->ID)
            return Search(root->left, id);
        return Search(root->right, id);
    }

    void updateQuantity(int id, int q)
    {
        Node *n = Search(root, id);
        if (n != nullptr)
        {
            n->update(q);
            cout << "Quantity updated for ID: " << id << endl;
        }
        else
        {
            cout << "Item with ID " << id << " not found!" << endl;
        }
    }

    Node *getMaxQuan(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        Node *maxLeft = getMaxQuan(root->left);
        Node *maxRight = getMaxQuan(root->right);

        Node *maxQuan = root;

        if (maxLeft && maxLeft->quantity > maxQuan->quantity)
            maxQuan = maxLeft;
        if (maxRight && maxRight->quantity > maxQuan->quantity)
            maxQuan = maxRight;

        return maxQuan;
    }
    Node *getRoot()
    {
        return root;
    }
};

int main()
{
    BinarySearchTree bst;

    bst.insert(101, 50);
    bst.insert(102, 30);
    bst.insert(103, 70);
    bst.insert(104, 20);
    bst.insert(105, 90);

    cout << "Initial products inserted.\n";

    bst.updateQuantity(103, 100);

    bst.updateQuantity(110, 25);

    Node *maxProd = bst.getMaxQuan(bst.getRoot());
    if (maxProd != nullptr)
    {
        cout << "\nProduct with highest quantity:\n";
        cout << "ID: " << maxProd->ID << ", Quantity: " << maxProd->quantity << endl;
    }
}