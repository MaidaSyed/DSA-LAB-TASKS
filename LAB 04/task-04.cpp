#include <iostream>
using namespace std;

bool findDuplicate(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] == arr[j]) return true;
        }
    }
    return false;
}

int main(){
    int arr[] = {1, 3, 4, 2, 2};
    int n = 5;

    cout<<"Array: ";
    for(int i=0; i<5; i++) cout<<arr[i]<<" ";
    cout<<endl;
    if(findDuplicate(arr, n)) cout<<"Duplicate exists"<<endl;
    else cout<<"Duplicate does not exists"<<endl;

    int arr1[] = {1, 3, 4, 2, 6};

    cout<<"Array: ";
    for(int i=0; i<5; i++) cout<<arr1[i]<<" ";
    cout<<endl;
    if(findDuplicate(arr1, n)) cout<<"Duplicate exists"<<endl;
    else cout<<"Duplicate does not exists"<<endl;
}