#include <iostream>
using namespace std;

struct Node{
    string book;
    Node* next;
    Node(string b){
        book = b;
        next = nullptr;
    }
};

class LibraryQueue{
    Node* front;
    Node* rear;
    public:
    LibraryQueue(){
        front = rear = nullptr;
    }

    void enqueue(string book){
        Node* newN = new Node(book);
        if(front == nullptr){
            front = rear = newN;
            rear->next = nullptr;
        }
        else{
            rear->next = newN;
            newN->next = nullptr;
            rear = newN;
        }
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

    void display(){
        Node* ptr = front;
        cout<<"Available Books: "<<endl;
        while(ptr != nullptr){
            cout<<ptr->book<<endl;
            ptr = ptr->next;
        }
    }
};

int main(){
    LibraryQueue mq;

    mq.enqueue("Data Structures!");
    mq.enqueue("Linear Algebra");
    mq.enqueue("Book 3");

    mq.dequeue();
    
    mq.display();
}