#include <iostream>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    Student()
    {
        rollNo = -1;
        name = "";
    }
};

class HashTable
{
    static const int size = 15;
    Student table[size];

public:
    int idx(int roll)
    {
        return roll % size;
    }

    void insert(int r, string n)
    {
        int index = idx(r);

        if (table[index].rollNo == -1)
        {
            table[index].rollNo = r;
            table[index].name = n;
            return;
        }

        for (int attempt = 1; attempt < size; attempt++)
        {
            int newIdx = (index + attempt * attempt) % size;

            if (table[newIdx].rollNo == -1)
            {
                table[newIdx].rollNo = r;
                table[newIdx].name = n;
                return;
            }
        }

        cout << "Student hash table is full" << endl;
    }

    void search(int r)
    {
        int index = idx(r);

        if (table[index].rollNo == r)
        {
            cout << "Student Found, Name: " << table[index].name << endl;
            return;
        }

        for (int attempt = 1; attempt < size; attempt++)
        {
            int newIdx = (index + attempt * attempt) % size;

            if (table[newIdx].rollNo == -1)
            {
                cout << "Record not found" << endl;
                return;
            }

            if (table[newIdx].rollNo == r)
            {
                cout << "Student Found, Name: " << table[newIdx].name << endl;
                return;
            }
        }
        cout << "Record not found" << endl;
    }

    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i].rollNo != -1)
                cout << i << ": (" << table[i].rollNo << ", " << table[i].name << ")\n";
            else
                cout << i << ": EMPTY\n";
        }
    }
};

int main()
{
    HashTable ht;

    ht.insert(20, "Ali");
    ht.insert(35, "Sara");
    ht.insert(50, "John");
    ht.insert(65, "Hina");
    ht.insert(80, "Hamza");

    cout << "\n--- Hash Table ---\n";
    ht.Display();

    cout << "\n--- Search ---\n";
    ht.search(50);
    ht.search(99);

    return 0;
}