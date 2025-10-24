#include <iostream>
using namespace std;

struct Node{
    string message;
    Node* next;
    Node(string s){
        message = s;
        next = nullptr;
    }
};

class MessageQueue{
    Node* front;
    Node* rear;
    public:
    MessageQueue(){
        front = rear = nullptr;
    }

    void enqueue(string msg){
        Node* newN = new Node(msg);
        if(front == nullptr){
            front = rear = newN;
            rear->next = nullptr;
        }
        else{
            rear->next = newN;
            newN->next = nullptr;
            rear = newN;
        }
        cout<<"Message: '"<<msg<<"' added to the queue"<<endl;
    }

    void dequeue(){
        if(front == nullptr) return;
        if(front->next == nullptr){
            delete front;
            front = nullptr;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }
};

int main(){
    MessageQueue mq;

    mq.enqueue("Hello!");
    mq.enqueue("How are you?");
    mq.enqueue("Message 3");

    cout << "Processing messages..." << endl;
    mq.dequeue();
    mq.dequeue();
    mq.dequeue();
}