#include<iostream>
using namespace std;

class base1{
    int data1;
    public:
        base1(int a){
            data1=a;
            cout<<"base1 constructor called"<<endl;
        } 

        void printnumbase1(){
            cout<<"The value of data1 is: "<<data1<<endl;
        }   
};

class base2{
    int data2;
    public:
        base2(int a){
            data2=a;
            cout<<"base2 constructor called"<<endl;
        } 

        void printnumbase2(){
            cout<<"The value of data2 is: "<<data2<<endl;
        }   
};

class derived: public base1,public base2{
    int derived1,derived2;
    public:
        derived(int a,int b,int c,int d): base1(a), base2(b){
            derived1 = c;
            derived2=d;
            cout<<"derived  class constructor called"<<endl;
        }

        void printnumderived(){
            cout<<"The value of derived1 is: "<<derived1<<endl;
             cout<<"The value of derived2 is: "<<derived2<<endl;
        }

};


int main(){

    derived a(12,13,14,15);
    a.printnumbase1();
    a.printnumbase2();
    a.printnumderived();
    return 0; 
}