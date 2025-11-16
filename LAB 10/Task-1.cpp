#include <iostream>
using namespace std;

#define MAX 100

class MaxHeap{
    public:
    int arr[MAX];
    int size;

    MaxHeap(){
        size = 0;
    }

    void insert(int val){
        arr[size] = val;
        heapifyUp(size);
        size++;
    }

    void heapifyUp(int i){
        while(i > 0){
            int parent = (i-1) / 2;
            if(arr[parent] < arr[i]){
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else break;
        }
    }

    void heapifyDown(int i){
        while(true){
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;

            if(left < size && arr[left] > arr[largest]) largest = left;

            if(right < size && arr[right] > arr[largest]) largest = right;

            if(largest != i){
                swap(arr[i], arr[largest]);
                i = largest;
            }else break;
        }
    }

    void updateKey(int i, int newV){
        if(i < 0 || i >= size){
            cout<<"Invalid index";
            return;
        }

        int old = arr[i];
        arr[i] = newV;

        if(newV > old) heapifyUp(i);
        else heapifyDown(i);
    }

    void delKey(int i){
        if(i < 0 || i >= size) return;

        arr[i] = arr[size-1];
        size--;
        heapifyDown(i);
    }

    void print(){
        for(int i=0; i<size; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    MaxHeap h;

    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);

    cout << "Initial Heap: ";
    h.print();

    // Update index 2 with new value 10
    h.updateKey(2, 10);
    cout << "After update: ";
    h.print();

    // Delete index 1
    h.delKey(1);
    cout << "After delete: ";
    h.print();
}