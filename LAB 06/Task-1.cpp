#include <iostream>
using namespace std;

struct Node{
    string data;
    Node* next;
    Node(string s){
        data = s;
        next = nullptr;
    }
};

class Stack{
    Node* head;
    Node* tail;
    public:
    Stack(){
        head = tail = nullptr;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    void push(string s){
        Node* newN = new Node(s);
        newN->next = head;
        head = newN;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty, nothing to pop"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

int main(){
    Stack s;
    s.pop();
    s.push("hello");
    if(s.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Stack is not empty"<<endl;
    }
}