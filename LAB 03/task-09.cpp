#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class NodeList
{
    Node *head;
    Node *tail;

public:
    NodeList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
        }
    }

    void performFunc()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        // 1- extracting alternative nodes
        Node *ptr = head;
        Node *tempHead = nullptr;
        Node *tempTail = nullptr;
        while (ptr != nullptr && ptr->next != nullptr)
        {
            Node *temp = ptr->next;
            ptr->next = temp->next;
            if (tempHead == nullptr)
            {
                tempHead = temp;
                tempTail = temp;
            }
            else
            {
                tempTail->next = temp;
                tempTail = temp;
            }

            tempTail->next = nullptr;
            if (ptr->next == nullptr)
            {
                tail = ptr;
            }
            ptr = ptr->next;
        }

        // 2- reversing alternative nodes
        Node *prev = nullptr;
        Node *currAlt = tempHead;
        while (currAlt)
        {
            Node *next = currAlt->next;
            currAlt->next = prev;
            prev = currAlt;
            currAlt = next;
        }
        tempHead = prev;

        // 3- appending reversed list
        tail->next = tempHead;

        if (tempHead != nullptr)
        {
            Node *newTail = tempHead;
            while (newTail->next != nullptr)
            {
                newTail = newTail->next;
            }
            tail = newTail; 
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    NodeList n;
    int arr[] = {10, 4, 9, 1, 3, 5, 9, 4};
    for (int x : arr)
    {
        n.insertAtEnd(x);
    }
    cout<<"Linked before reversing alternative node: ";
    n.display();

    n.performFunc();
    cout << endl;
    cout<<"Linked after reversing alternative node: ";
    n.display();
}
