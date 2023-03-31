#include<iostream>
using namespace std;

class numbers{
    public:

        int a;
        int b;

        numbers(int n1,int n2=5) : a(n1),b(a + n2)
        {
            cout<<"value of a is "<<a<<endl;
            cout<<"value of b is "<<b<<endl;
        }

};




int main(){

    numbers a1(-5);
    numbers a3(1,2);
    return 0;
}