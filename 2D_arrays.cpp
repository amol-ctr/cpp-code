#include<iostream>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter the no. of rows you want: ";
    cin>>m;
    cout<<"Enter the no. of columns you want in each row: ";
    cin>>n;

    int**p=new int*[m];

    for(int i=0;i<m;i++){
        p[i]=new int[n];
        for(int j=0;j<n;j++){
            int item;
            cout<<"enter the item you want to insert"<<endl;
            cin>>item;
            p[i][j]=item;
        }
    }

    // deallocating memory from array 
    for (int i = 0; i < m; i++)
    {
        delete [] p[i];
    }
    delete [] p;

    return 0;
}