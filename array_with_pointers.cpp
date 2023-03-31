#include <iostream>
using namespace std;

class shopitem
{
    int id, price;

public:
    void setdata(int a, int b)
    {
        id = a;
        price = b;
    }

    void getdata()
    {
        cout << "the id of item is: " << id << endl;
        cout << "the price of item is: " << price << endl;
    }
};
int main()
{

    int size = 3;
    shopitem *ptr = new shopitem[size];
    int p, q;
    for (int i = 0; i < size; i++)
    {
        cout << "enter the id and price of item: " << endl;
        cin >> p >> q;
        (ptr + i)->setdata(p, q);
    }

    for (int j = 0; j < size; j++)
    {
        (ptr + j)->getdata();
    }

    return 0;
}