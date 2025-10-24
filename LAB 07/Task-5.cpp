#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void push(int val) {
        Node* newN = new Node(val);
        newN->next = head;
        head = newN;
    }

    void swap(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    Node* getTail(Node* cur) {
        while (cur && cur->next)
            cur = cur->next;
        return cur;
    }

    Node* partition(Node* low, Node* high) {
        int pivot = high->data;
        Node* i = low;
        Node* j = low;

        while (j != high) {
            if (j->data < pivot) {
                swap(i, j);
                i = i->next;
            }
            j = j->next;
        }
        swap(i, high);
        return i;
    }

    void quickSortRec(Node* low, Node* high) {
        if (!low || low == high || !high)
            return;

        Node* p = partition(low, high);

        Node* temp = low;
        while (temp && temp->next != p)
            temp = temp->next;

        if (temp != p)
            quickSortRec(low, temp);

        if (p && p->next)
            quickSortRec(p->next, high);
    }

    void quickSort() {
        Node* tail = getTail(head);
        quickSortRec(head, tail);
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout <<"nullptr"<< endl;
    }
};

int main() {
    LinkedList list;
    list.push(3);
    list.push(5);
    list.push(1);
    list.push(9);
    list.push(8);
    list.push(7);
    list.push(10);

    cout<<"Orginal linked list: ";
    list.printList();

    list.quickSort();

    cout<<"Sorted linked list: ";
    list.printList();
}
