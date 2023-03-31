#include<iostream>
using namespace std;
int main(){

    int l[]={11,10,12,15,14};

    for(int i=1;i<5;i++){
        int key=l[i];
        int j=i-1;
        while((j>=0) && (key<l[j])){
            l[j+1]=l[j];
            j-=1;
        }
        l[j+1]=key;
    }
    cout<<l[0]<<endl<<l[1]<<endl<<l[2]<<endl<<l[3]<<endl<<l[4];
    return 0;
}