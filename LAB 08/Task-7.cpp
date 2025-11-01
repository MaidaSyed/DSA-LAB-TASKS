#include <iostream>
#include <vector>
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

    Node *insertion(Node *n, int v)
    {
        if (n == nullptr)
        {
            return new Node(v);
        }
        else if (v < n->val)
        {
            n->left = insertion(n->left, v);
        }
        else if (v > n->val)
        {
            n->right = insertion(n->right, v);
        }
        return n;
    }
    void insert(int v, int q)
    {
        root = insertion(root, v);
    }

    void inOrder(Node* n, vector<int>& vals){
        if(n == nullptr) return;
        inOrder(n->left, vals);
        vals.push_back(n->val);
        inOrder(n->right, vals);
    }

    void findMedian(){
        vector<int> vals;
        inOrder(root, vals);

        int n = vals.size();
        double median = 0.0;
        if(n % 2 == 0){
            median = (vals[n/2 -1] + vals[n/2] ) /2.0;
        }
        else{
            median = vals[n/2];
        }
        cout<<"median of BST: "<<median<<endl;
    }

    int countInRange(Node* n, int st, int end){
        if(n == nullptr) return 0;
        
        if(n->val >= st && n->val <= end){
            return 1 + countInRange(n->left, st, end) + countInRange(n->right, st, end);
        }
        else if(n->val < st) return countInRange(n->right, st, end);
        else return countInRange(n->left, st, end);
    }
    int countInRange(int a, int b){
        return countInRange(root, a, b);
    }

    
    Node *getRoot()
    {
        return root;
    }
};

int main()
{
    BinarySearchTree bst;

    bst.insert(10, 0);
    bst.insert(5, 0);
    bst.insert(1, 0);
    bst.insert(40, 0);
    bst.insert(50, 0);
    bst.insert(100, 0);

    cout << "Finding Median of BST..." << endl;
    bst.findMedian();

    int a = 5, b = 45;
    cout << "\nRange: [" << a << ", " << b << "]" << endl;
    cout << "Count of nodes in range: " << bst.countInRange(a, b) << endl;

    return 0;

}