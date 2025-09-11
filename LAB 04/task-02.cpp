#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void insertMaxAtMid(int arr[], int n){
    for(int i=n-1; i>n/2; i--){
        int temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp; 
    }
}

int main(){
    int size;
    cout<<"Enter size of arr: ";
    cin>>size;
    int arr[size];
    cout<<"Enter values:"<<endl;
    for(int i=0; i<size; i++) {
        cout<<"val "<<i+1<<" : ";
        cin>>arr[i];
    }
    
    insertionSort(arr, size);
    insertMaxAtMid(arr, size);

    cout<<"Sorted Array(max elem in middle): ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
}
