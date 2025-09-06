#include <iostream>
using namespace std;

class Product
{
    string name;
    double price;
    int stock;

public:
    Product(string n, double p, int s) : name(n), price(p), stock(s) {};

    void applyDiscount(double percent)
    {
        price -= price * (percent / 100.0);
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
    }
};

class Bundle
{
    Product **prod;
    int count;
    int capacity;
    double discount;

public:
    Bundle(double d, int cap = 20)
    {
        discount = d;
        capacity = cap;
        count = 0;
        prod = new Product *[capacity];
    }

    void addProd(Product *p)
    {
        if (count < capacity)
        {
            prod[count++] = p;
        }
    }

    void applyDiscount()
    {
        for (int i = 0; i < count; i++)
        {
            prod[i]->applyDiscount(discount);
        }
    }

    void display()
    {
        cout << "\n--- Bundle Details ---" << endl;
        cout << "Discount: " << discount << "%" << endl;
        for (int i = 0; i < count; i++)
        {
            prod[i]->display();
        }
        cout << "----------------------" << endl;
    }

    // shallow copy
    Bundle(const Bundle &b)
    {
        discount = b.discount;
        capacity = b.capacity;
        count = b.count;
        prod = b.prod; // same product
    }

    // deep copy
    Bundle(const Bundle &b, bool deepCopy)
    {
        discount = b.discount;
        capacity = b.capacity;
        count = b.count;
        if (deepCopy)
        {
            prod = new Product *[capacity];
            for (int i = 0; i < count; i++)
            {
                prod[i] = new Product(*b.prod[i]);
            }
        }
    }

    ~Bundle()
    {
        delete[] prod;
    }
};

int main()
{
    // Create some products
    Product *p1 = new Product("Laptop", 1000, 5);
    Product *p2 = new Product("Phone", 500, 10);
    Product *p3 = new Product("Headphones", 100, 20);

    // Original bundle
    Bundle original(10); // 10% discount
    original.addProd(p1);
    original.addProd(p2);
    original.addProd(p3);

    cout << "Original Bundle:" << endl;
    original.display();

    // Shallow copy
    Bundle shallowCopy = original;

    // Deep copy
    Bundle deepCopy(original, true);

    // Apply discount to original
    original.applyDiscount();

    cout << "\nAfter applying discount to ORIGINAL bundle:" << endl;
    cout << "Original:";
    original.display();

    cout << "Shallow Copy (affected):";
    shallowCopy.display();

    cout << "Deep Copy (independent):";
    deepCopy.display();

    // Cleanup
    delete p1;
    delete p2;
    delete p3;

    return 0;
}