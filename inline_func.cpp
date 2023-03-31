#include<iostream>
using namespace std;

// Inline functions copy the entire code to the line where function is called
// It increases readability as well as performance 
// A function with max 2-3 lines only can be made inline else it is of no use
inline int max(int a1,int a2){
    return (a1>a2)? a1 : a2;    // This line indicates if a1 is greater than a2 than a1 is returned else a2 is 
}                              //  returned.

int main(){

    int a,b;
    cin>>a>>b;
    int c=max(a,b);
    cout<<c<<endl;
    return 0;
}