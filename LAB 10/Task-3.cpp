#include <iostream>
using namespace std;

int kLargestElem(int arr[], int n, int k){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] < arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
    return arr[k-1];
}

int main(){
    int arr1[] = {1, 23, 12, 9, 30, 2, 50}; 
    int k = 3;

    int res = kLargestElem(arr1, sizeof(arr1)/sizeof(arr1[0]), k);

    cout<<k<<" largest element is: "<<res<<endl;

    int arr2[] = {12, 3, 5, 7, 19}; 
    int k2 = 2;

    int res2 = kLargestElem(arr2, sizeof(arr2)/sizeof(arr2[0]), k2);

    cout<<k2<<" largest element is: "<<res2<<endl;
}