#include <iostream>
using namespace std;

class Queue{
    int size;
    int count;
    int *arr;
    public:
    Queue(int s){
        size = s;
        count = 0;
        arr = new int[size];
    }

    void enqueue(int ID){
        if(count >= size){
            cout<<"Queue full"<<endl;
            return;
        }
        arr[count++] = ID;
        cout<<"ID: "<<ID<<" added to queue"<<endl;
    }

    int dequeue(){
        int res = arr[0];
        for(int i=0; i<count; i++){
            arr[i] = arr[i+1];
        }
        return res;
    }

    ~Queue(){
        delete[] arr;
    }
};

int main(){
    Queue q(7);
    q.enqueue(13);
    q.enqueue(7);
    q.enqueue(4);
    q.enqueue(1);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    q.enqueue(7);
}