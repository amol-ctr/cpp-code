#include<iostream>
using namespace std;

class A{
    public:
        void greet(){
            cout<<"hello how are you?"<<endl;
        }
};

class B{
    public:
        void greet(){
            cout<<"hello! Nice to meet you"<<endl;
        }
};

class C:public A,public B{
    public:
        void greet(){
            A::greet();
        }

};

int main(){

    C c1;
    c1.greet();

    return 0;
}