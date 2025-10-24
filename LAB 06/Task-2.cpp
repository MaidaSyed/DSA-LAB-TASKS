#include <iostream>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node(string s) {
        url = s;
        next = nullptr;
    }
};

class NodeList {
    Node* head;
public:
    NodeList() {
        head = nullptr;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    void addToFront(string s) {
        Node* newN = new Node(s);
        newN->next = head;
        head = newN;
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "List is empty, nothing to remove." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        Node* ptr = head;
        cout << "Browsing History: ";
        while (ptr != nullptr) {
            cout << ptr->url << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

class Stack {
    Node* head;
public:
    Stack() {
        head = nullptr;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    void push(string s) {
        Node* newN = new Node(s);
        newN->next = head;
        head = newN;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, nothing to pop." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    string top() {
        if (isEmpty()) {
            return "No pages";
        }
        return head->url;
    }

    void display() {
        Node* ptr = head;
        cout << "Stack contents: ";
        while (ptr != nullptr) {
            cout << ptr->url << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    NodeList history;
    Stack backStack;

    // User visits websites
    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (string site : sites) {
        history.addToFront(site);
        backStack.push(site);
    }

    cout << "Initial state:" << endl;
    history.display();

    // User clicks 'Back' twice
    cout << "\nUser clicks 'Back' twice...\n";
    for (int i = 0; i < 2; ++i) {
        if (!backStack.isEmpty()) {
            cout << "Going back from: " << backStack.top() << endl;
            backStack.pop();
            history.removeFront();
        }
    }

    cout << "\nAfter going back twice:" << endl;
    history.display();

    if (!backStack.isEmpty())
        cout << "Current page: " << backStack.top() << endl;

    return 0;
}
