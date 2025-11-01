#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int rollNo;
    int score;

    Student() {};
    Student(string n, int r, int s) : name(n), rollNo(r), score(s) {};
};

struct Node
{
    Student s;
    Node *left;
    Node *right;
    Node(Student s)
    {
        this->s = s;
        left = right = nullptr;
    }
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }

    Node *insert(Node *root, Student s)
    {
        if (root == NULL)
            return new Node(s);
        if (s.name < root->s.name)
            root->left = insert(root->left, s);
        else
            root->right = insert(root->right, s);
        return root;
    }

    void insert(Student s)
    {
        root = insert(root, s);
    }

    Node *findMin(Node *node)
    {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node *removeLowScores(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        root->left = removeLowScores(root->left);
        root->right = removeLowScores(root->right);

        if (root->s.score < 10)
        {
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node *temp = findMin(root->right);
                root->s = temp->s;
                root->right = removeLowScores(root->right);
            }
        }
        return root;
    }
    void removeLowScores()
    {
        root = removeLowScores(root);
    }

    Node *SearchMaxScore(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        Node *maxLeft = SearchMaxScore(root->left);
        Node *maxRight = SearchMaxScore(root->right);

        Node *maxScore = root;

        if (maxLeft && maxLeft->s.score > maxScore->s.score)
            maxScore = maxLeft;
        if (maxRight && maxRight->s.score > maxScore->s.score)
            maxScore = maxRight;

        return maxScore;
    }

    Node *Search(Node *root, string n)
    {
        if (root == nullptr || root->s.name == n)
            return root;
        if (n < root->s.name)
            return Search(root->left, n);
        return Search(root->right, n);
    }
    Node *Search(string n)
    {
        return Search(root, n);
    }

    void displayInOrder(Node *root)
    {
        if (root == nullptr)
            return;
        displayInOrder(root->left);
        cout << root->s.name << " (Roll: " << root->s.rollNo
             << ", Marks: " << root->s.score << ")\n";
        displayInOrder(root->right);
    }

    void display()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty.\n";
            return;
        }
        displayInOrder(root);
    }

    Node *getRoot()
    {
        return root;
    }
};

int main()
{
    srand(time(0));

    BST tree;

    Student students[10] = {
        Student("Maida", 1, 95),
        Student("Batool", 2, 7),
        Student("Neamah", 3, 15),
        Student("Kiran", 4, 3),
        Student("Aila", 5, 40),
        Student("Saim", 6, 25),
        Student("Bilal", 7, 60),
        Student("Pareena", 8, 9),
        Student("Hasan", 9, 78),
        Student("Zoha", 10, 55)};

    cout << "----- Randomly inserting 7 students into the tree -----\n\n";

    bool used[10] = {false};
    int count = 0;

    while (count < 7)
    {
        int index = rand() % 10;
        if (!used[index])
        {
            tree.insert(students[index]);
            used[index] = true;
            cout << "Added: " << students[index].name
                 << " (Roll: " << students[index].rollNo
                 << ", Marks: " << students[index].score << ")\n";
            count++;
        }
    }

    cout << "\n----- Students in tree (in-order traversal) -----\n";
    tree.display();

    string searchName;
    cout << "\nEnter student name to search: ";
    cin >> searchName;

    Node *found = tree.Search(searchName);
    if (found)
        cout << "\n"
             << searchName << " found with marks " << found->s.score << ".\n";
    else
        cout << "\n"
             << searchName << " not found in the tree.\n";

    cout << "\nRemoving students who scored less than 10...\n";
    tree.removeLowScores();

    cout << "\n----- After deletion of low scorers -----\n";
    tree.display();

    Node *topper = tree.SearchMaxScore(tree.getRoot());
    if (topper)
        cout << "\nTopper of the class is: " << topper->s.name
             << " (Roll: " << topper->s.rollNo
             << ", Marks: " << topper->s.score << ")\n";
    else
        cout << "\nNo students left in the tree.\n";

    return 0;
}
