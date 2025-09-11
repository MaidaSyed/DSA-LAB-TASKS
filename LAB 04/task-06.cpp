#include <iostream>
using namespace std;

int getMax(int arr[], int n){
    int maxNum = arr[0];
    for(int i=1; i<n; i++) maxNum = max(maxNum, arr[i]);
    return maxNum;
}

void countingSortByDigit(int arr[], int n, int exp){
    int output[n];
    int count[10] = {0};

    for(int i=0; i<n; i++){
        int digit = (arr[i]/exp) % 10;
        count[digit]++;
    }

    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }

    for(int i=n-1; i>=0; i--){
        int digit = (arr[i]/exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n){
    int maxNum = getMax(arr, n);
    int exp = 1;
    while(maxNum / exp > 0){
        countingSortByDigit(arr, n, exp);
        exp *= 10;
    }
}

int main(){
    int arr[] = {452913, 100234, 987654, 321456, 654123, 123456};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Application IDs:"<<endl;
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;

    radixSort(arr, n);

    cout<<"\nSorted Application IDs:"<<endl;
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;

}