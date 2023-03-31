#include<iostream>
#include<cmath>
using namespace std;

int pow(int num,int power){
    if(power==0){
        return 1;
    }
    else{
        int i=1;
        int result=1;
        while(i<=power){
            result*=num;
            i++;
        }
    return result;
    }
}

class complex{
    int a,b;
    public:

        complex(void); //----> this is a default constructor

        void printnum(void){
            cout<<"the value of complex is: "<<a<<" + "<<b<<"i"<<endl;
        }
};

class point{
    int a,b;
    public:

        point(int ,int);

        void displaypointer(){
            cout<<"the point is: ("<<a<<" , "<<b<<")"<<endl;
        }

        friend void displaydistance(point,point);
};

point::point(int x,int y){
    a=x;
    b=y;
}

void displaydistance(point a1,point a2){
    int x1=(a1.a)-(a2.a);
    int y1=(a1.b)-(a2.b);
    int d1=pow(x1,2) + pow(y1,2);
    double d=sqrt(double(d1));
    cout<<"distance is: "<<d<<endl;
}

complex::complex(void){
    a=10;
    b=20;
}
int main(){

    complex c1;
    c1.printnum();

    point a1(3,5);
    a1.displaypointer();

    point a2(2,3);
    a2.displaypointer();

    displaydistance(a1,a2);

    return 0;
}