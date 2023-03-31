#include<iostream>
using namespace std;
int main(){
    cout<<"enter the number of items you want to insert in the list: ";
    int n;
    cin>>n;
    int l1[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter the item "<<i+1<<": ";
        int item;
        cin>>item;
        l1[i]=item;
    }
    int* p=l1;  //---> FOR COPYING ONE LIST TO ANOTHER
    cout<<"your required list is:\n";
    cout<<"[";
    for (int j = 0; j < n-1 ; j++)
    {
       cout<<p[j]<<",";
    }
    cout<<p[n-1]<<"]";
    
    return 0;
}