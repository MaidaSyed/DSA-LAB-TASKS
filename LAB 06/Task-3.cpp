#include <iostream>
using namespace std;

struct Node{
    char data;
    Node* next;
    Node(char c){
        data = c;
        next = nullptr;
    }
};

class Stack{
    Node* head;
    public:
    Stack(){
        head = nullptr;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    char top() {
        if (isEmpty()) {
            return '\0';
        }
        return head->data;
    }

    void push(char c){
        Node* newN = new Node(c);
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

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string infix){
    Stack st;
    string postfix = "";

    for(char c : infix){
        if(isalnum(c)) postfix += c;
        else if(c == '(') st.push(c);
        else if(c == ')'){
            while((!st.isEmpty() && st.top() !='(')){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.isEmpty() && precedence(st.top()) >= precedence(c)){
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.isEmpty()){
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main(){
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);

    cout<<"Infix: "<<infix<<endl;
    cout<<"Postfix: "<<postfix<<endl;
}