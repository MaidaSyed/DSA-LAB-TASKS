#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class HashTable
{
    int size;
    list<int> *table;

public:
    HashTable(int s)
    {
        size = s;
        table = new list<int>[size];
    }
    void insert(int key, int val)
    {
        if (key >= size)
        {
            cout << "Invalid index" << endl;
            return;
        }
        table[key].push_front(val);
    }

    void del(int key, int val)
    {
        if (key >= size)
        {
            cout << "Invalid index" << endl;
            return;
        }
        table[key].remove(val);
        cout<<val<<" is deleted"<<endl;
    }

    void search(int val)
    {
        for (int i = 0; i < size; i++)
        {
            auto it = find(table[i].begin(), table[i].end(), val);
            if (it != table[i].end())
            {
                cout << "value found at index " << i << endl;
                return;
            }
        }
        cout << "value not found." << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            for (int val : table[i])
                cout<<i << ": " << val << " -> ";
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    HashTable ht(10);

    ht.insert(0, 5);
    ht.insert(1, 6);
    ht.insert(2, 8);
    ht.insert(3, 5);
    ht.insert(4, 6);
    ht.insert(5, 8);
    ht.insert(6, 5);
    ht.insert(7, 6);
    ht.insert(8, 8);
    ht.insert(9, 5);
    ht.insert(1, 9);
    ht.insert(1, 2);
    ht.insert(5, 0);

    ht.display();

    ht.del(1, 9);
    ht.display();
}
