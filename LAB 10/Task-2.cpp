#include <iostream>
using namespace std;

bool isBin(int arr[], int n)
{
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[i])
            return false;

        if (right < n && arr[right] > arr[i])
            return false;
    }
    return true;
}

#define MAX 100

class MaxHeap
{
public:
    int arr[MAX];
    int size;

    MaxHeap()
    {
        size = 0;
    }

    void insert(int val)
    {
        arr[size] = val;
        heapifyUp(size);
        size++;
    }

    void heapifyUp(int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (arr[parent] < arr[i])
            {
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else
                break;
        }
    }

    void heapifyDown(int i)
    {
        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && arr[left] > arr[largest])
                largest = left;

            if (right < size && arr[right] > arr[largest])
                largest = right;

            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
                break;
        }
    }

    bool isBinHeap()
    {
        for (int i = 0; i <= (size - 2) / 2; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && arr[left] > arr[i])
                return false;

            if (right < size && arr[right] > arr[i])
                return false;
        }
        return true;
    }

    void Sort()
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
            heapifyDown(i);

        for (int i = size - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);

            int tempSize = i;

            int root = 0;
            int largest = root;

            while (true)
            {
                int left = 2 * root + 1;
                int right = 2 * root + 2;

                largest = root;

                if (left < tempSize && arr[left] > arr[largest])
                    largest = left;

                if (right < tempSize && arr[right] > arr[largest])
                    largest = right;

                if (largest != root)
                {
                    swap(arr[root], arr[largest]);
                    i = largest;
                }
                else
                    break;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    MaxHeap h;

    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);

    cout << "Initial Heap: ";
    h.print();

    if(h.isBinHeap()) cout<<"This array is a Binary Heap"<<endl;
    else cout<<"This array is not a Binary Heap"<<endl;

    h.Sort();

    cout<<"After sorting: ";
    h.print();
}