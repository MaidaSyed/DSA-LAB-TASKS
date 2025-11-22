#include <iostream>
using namespace std;

struct Pair
{
    int a;
    int b;
    Pair(int x = 0, int y = 0)
    {
        a = x;
        b = y;
    }
};

class HashTable
{
    static const int size = 10;
    Pair table[size];

public:
    HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            table[i] = Pair(-1, -1);
        }
    }

    int idx(int sum)
    {
        return sum % size;
    }

    bool checkDistinct(Pair p1, Pair p2)
    {
        return (p1.a != p2.a && p1.a != p2.b &&
                p1.b != p2.a && p1.b != p2.b);
    }

    bool check(int x, int y, Pair &p1, Pair &p2)
    {
        int sum = x + y;
        int index = idx(sum);

        for (int i = 0; i < size; i++)
        {
            if (table[i].a != -1 && table[i].b != -1)
            {
                if (table[i].a + table[i].b == sum)
                {
                    if (checkDistinct(table[i], Pair(x, y)))
                    {
                        p1 = table[i];
                        p2 = Pair(x, y);
                        return true;
                    }
                }
            }
        }

        table[index] = Pair(x, y);
        return false;
    }
};

int main(){
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = 7;

    HashTable ht;
    Pair p1, p2;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(ht.check(arr[i], arr[j], p1, p2)){
                cout << "Output: " << "(" << p1.a << ", " << p1.b << ") and ("
                     << p2.a << ", " << p2.b << ")" << endl;
                return 0;
            }
        }
    }

    return 1;
}