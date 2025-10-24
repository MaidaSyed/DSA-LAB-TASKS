#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeTwoLists(int arr1[], int arr2[], int n1, int n2, int merged[]) {
    for (int i = 0; i < n1; i++)
        merged[i] = arr1[i];
    for (int j = 0; j < n2; j++)
        merged[n1 + j] = arr2[j];
}

int main() {
    int arr1[10] = {12, 3, 45, 7, 23, 56, 8, 19, 34, 2};
    int arr2[10] = {5, 11, 29, 1, 67, 33, 4, 22, 9, 15};

    int merged[20];
    mergeTwoLists(arr1, arr2, 10, 10, merged);

    cout << "Combined Array: ";
    for (int i = 0; i < 20; i++)
        cout << merged[i] << " ";
    cout << endl;

    radixSort(merged, 20);

    cout << "Sorted Array using Radix Sort: ";
    for (int i = 0; i < 20; i++)
        cout << merged[i] << " ";
    cout << endl;

    mergeSort(merged, 0, 19);

    cout << "Sorted Array using Merge Sort: ";
    for (int i = 0; i < 20; i++)
        cout << merged[i] << " ";
    cout << endl;

    return 0;
}
