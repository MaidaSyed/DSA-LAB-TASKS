#include <iostream>
using namespace std;

void bubbleSort(string arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]) swap(arr[i], arr[j]);
        }
    }
}

int main(){
    string arr[] = {"banana", "apple", "cherry", "date", "grape"};

    cout<<"Unsorted strings: ";
    for(int i=0; i<5; i++) cout<<arr[i]<<" ";

    bubbleSort(arr, 5);
    cout<<endl<<"Sorted strings: ";
    for(int i=0; i<5; i++) cout<<arr[i]<<" ";
}