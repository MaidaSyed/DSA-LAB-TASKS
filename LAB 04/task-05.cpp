#include <iostream>
using namespace std;

void countingSortForYears(int arr[], int n){
    int minYear = 2022;
    int range = 3;
    int count[range] = {0};
    int output[n];

    for(int i=0; i<n; i++){
        count[arr[i] - minYear]++;
    }

    for(int i=1; i<range; i++){
        count[i] += count[i-1];
    }

    for(int i=n-1; i>=0; i--){
        output[count[arr[i] - minYear] - 1] = arr[i];
        count[arr[i] - minYear]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

int main(){
    int arr[] = {2022, 2023, 2024, 2022, 2023, 2024};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Unsorted years: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";

    countingSortForYears(arr, size);
    
    cout<<endl<<"Sorted years: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
}