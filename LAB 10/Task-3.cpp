#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) largest = left;

    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void maxHeap(int arr[], int n){
    for(int i=n/2-1; i>=0; i--) heapify(arr, n, i);
}

int extractMax(int arr[], int &n){
    if(n <= 0) return -1;

    int maxVal = arr[0];
    arr[0] = arr[n-1];
    n--;
    heapify(arr, n, 0);
    return maxVal;
}

int kLargestElem(int arr[], int n, int k){
    maxHeap(arr, n);

    int val = -1;
    for(int i=0; i<k; i++){
        val = extractMax(arr, n);
    }
    return val;
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