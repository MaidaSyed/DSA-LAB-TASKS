#include <iostream>
using namespace std;

int recursiveArraySum(void* arr, int sizes[], int dim) {
    int sum = 0;

    if (dim == 1) {
        // Base case: simple 1D array
        int* row = (int*)arr;
        for (int i = 0; i < sizes[0]; i++) {
            sum += row[i];
        }
    } else {
        // Recursive case: array of pointers
        void** subArr = (void**)arr;
        for (int i = 0; i < sizes[0]; i++) {
            sum += recursiveArraySum(subArr[i], sizes + 1, dim - 1);
        }
    }

    return sum;
}

int main() {
    // Example: 2D jagged array
    int a1[] = {1, 2, 3};
    int a2[] = {4, 5};
    int a3[] = {6, 7, 8, 9};

    int* arr[] = {a1, a2, a3};

    // Sizes for each dimension
    int sizes[] = {3}; // top-level has 3 subarrays

    // Call recursive sum
    int total = 0;
    for (int i = 0; i < sizes[0]; i++) {
        int subSizes[] = { (i == 0 ? 3 : (i == 1 ? 2 : 4)) };
        total += recursiveArraySum(arr[i], subSizes, 1);
    }

    cout << "Sum of all elements = " << total << endl;
    return 0;
}
