#include <iostream>
using namespace std;

void selectionSort(int arr[10], int n){
    for(int i=0; i<n-1; i++){
        int smallIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[smallIdx]) smallIdx = j;
        }
        swap(arr[i], arr[smallIdx]);
    }
}

int main(){
    int arr[10];
    cout<<"Enter 10 values to sort:"<<endl;
    for(int i=0; i<10; i++) cin>>arr[i];

    selectionSort(arr, 10);
    cout<<"Four minimum elements: ";
    for(int i=0; i<4; i++) cout<<arr[i]<<" ";
}