#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (true) {
        while (i <= high && arr[i] <= pivot) { i++; comparisons++; }
        while (arr[j] > pivot) { j--; comparisons++; }
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

int partitionMiddle(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    swap(arr[low], arr[mid]);
    return partitionFirst(arr, low, high);
}

int partitionRandom(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[low], arr[randomIndex]);
    return partitionFirst(arr, low, high);
}

int partitionMedian(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];
    int median;
    if ((a > b) != (a > c)) median = low;
    else if ((b > a) != (b > c)) median = mid;
    else median = high;
    swap(arr[low], arr[median]);
    return partitionFirst(arr, low, high);
}

void quickSort(int arr[], int low, int high, int mode) {
    if (low < high) {
        int p;
        if (mode == 1) p = partitionFirst(arr, low, high);
        else if (mode == 2) p = partitionRandom(arr, low, high);
        else if (mode == 3) p = partitionMiddle(arr, low, high);
        else p = partitionMedian(arr, low, high);

        quickSort(arr, low, p - 1, mode);
        quickSort(arr, p + 1, high, mode);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void testAll(int arr[], int n) {
    int temp[10];

    cout << "\nOriginal Array: ";
    printArray(arr, n);

    int modes[4] = {1, 2, 3, 4};
    string names[4] = {"First Element", "Random Element", "Middle Element", "Median of Three"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) temp[j] = arr[j];
        comparisons = 0;
        quickSort(temp, 0, n - 1, modes[i]);
        cout << "\nPivot: " << names[i] << endl;
        cout << "Sorted: ";
        printArray(temp, n);
        cout << "Comparisons: " << comparisons << endl;
    }
}

int main() {
    srand(time(0));
    int sorted[10] = {1,2,3,4,5,6,7,8,9,10};
    int reverseSorted[10] = {10,9,8,7,6,5,4,3,2,1};
    int randomArr[10] = {5,2,9,1,8,3,7,6,10,4};

    cout << "\n--- Sorted Array ---";
    testAll(sorted, 10);

    cout << "\n--- Reverse Sorted Array ---";
    testAll(reverseSorted, 10);

    cout << "\n--- Random Array ---";
    testAll(randomArr, 10);
}
