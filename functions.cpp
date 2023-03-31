#include<iostream>
using namespace std;
int sum(int,int);
void g();
int* swapreference(int &a,int &b){
    int c=b;
    b=a;
    a=c;
    return &b;
}
int main(){
    int n1;
    int n2;
    cout<<"enter first no.: ";
    cin>>n1;
    cout<<"enter second no.: ";
    cin>>n2;
    cout<<&n1<<endl<<&n2<<endl;
    cout<<"the sum of two no.s entered is: "<<sum(n1,n2);
    g();
    int* n3=swapreference(n1 , n2);
    cout<<*n3<<endl;
    cout<<"Now the value of n1 is "<<n1<<" and the value of n2 is "<<n2;
    return 0;
}
int sum(int a,int b){
    int c=a+b;
    return c ;
}
void g(){
    cout<<"\nThanks for using the function.\n";
}