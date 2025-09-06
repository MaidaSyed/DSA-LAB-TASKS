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

    void EvenOdd()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        // detaching odd nodes only
        Node *curr = head;
        Node *prev = nullptr;

        Node *oddHead = nullptr;
        Node *oddTail = nullptr;

        while (curr != nullptr)
        {
            if (curr->data % 2 != 0)
            { 
                if (prev != nullptr)
                {
                    prev->next = curr->next;
                }
                else
                {
                    head = curr->next;
                }

                // add to odd sublist
                if (oddHead == nullptr)
                {
                    oddHead = curr;
                    oddTail = curr;
                }
                else
                {
                    oddTail->next = curr;
                    oddTail = curr;
                }

                curr = curr->next;
                oddTail->next = nullptr; 
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        // Append odd list at the end
        if (oddHead != nullptr)
        {
            if (tail != nullptr)
            {
                tail->next = oddHead;
            }
            else
            {
                head = oddHead;
            }
            tail = oddTail;
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
    int arr[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    for (int x : arr)
        n.insertAtEnd(x);

    cout << "Original List:" << endl;
    n.display();

    n.EvenOdd();

    cout << "Modified List:" << endl;
    n.display();
}
