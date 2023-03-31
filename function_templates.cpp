#include<iostream>
using namespace std;

template<class T1,class T2>
int avg(T1 a,T2 b){
    float avg=(a+b)/2.0;
    return avg;
}

int main(){

    float av;
    float a;
    float b;
    printf("enter the numbers: \n");
    scanf("%f%f",&a,&b);
    av=avg(a,b);
    printf("The average of given numbers is %f\n",av);

    return 0;
}