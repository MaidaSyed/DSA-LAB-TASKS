#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) {
        data = d;
        next = nullptr;
    }
};

class Stack {
    Node* head;
public:
    Stack() {
        head = nullptr;
    }
    bool isEmpty() { return head == nullptr; }
    void push(string val) {
        Node* newN = new Node(val);
        newN->next = head;
        head = newN;
    }
    string top() {
        if (isEmpty()) return "";
        return head->data;
    }
    void pop() {
        if (isEmpty()) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

// precedence of operators
int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// infix to postfix conversion
string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isdigit(c) || c == '.') {  // handle multi-digit or decimal
            postfix += c;
        } else if (c == '(') {
            postfix += ' ';
            st.push("(");
        } else if (c == ')') {
            postfix += ' ';
            while (!st.isEmpty() && st.top() != "(") {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            postfix += ' ';
            while (!st.isEmpty() && prec(st.top()[0]) >= prec(c)) {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            string s(1, c);
            st.push(s);
        }
    }

    while (!st.isEmpty()) {
        postfix += ' ';
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

// evaluate postfix expression
float evalPostfix(string exp) {
    Stack st;
    string num = "";
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (isdigit(c) || c == '.') {
            num += c;
        } else if (c == ' ' && num != "") {
            st.push(num);
            num = "";
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            float b = stof(st.top()); st.pop();
            float a = stof(st.top()); st.pop();
            float res;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else res = a / b;
            st.push(to_string(res));
        }
    }
    return stof(st.top());
}

int main() {
    string expression = "12+13-5*(0.5+0.5)+1";
    cout << "Infix: " << expression << endl;

    string postfix = infixToPostfix(expression);
    cout << "Postfix: " << postfix << endl;

    float result = evalPostfix(postfix);
    cout << "Result: " << result << endl;

    // Maintain final stack with x and =
    Stack finalStack;
    finalStack.push(to_string((int)result));
    finalStack.push("=");
    finalStack.push("x");

    cout << "\nFinal Stack (top to bottom):" << endl;
    while (!finalStack.isEmpty()) {
        cout << finalStack.top() << " ";
        finalStack.pop();
    }
    cout << endl;

    return 0;
}
