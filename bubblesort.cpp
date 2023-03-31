#include<iostream>

using namespace std;

int main(){

    int l[]={15,13,11,14,12};

    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(l[j]>l[j+1]){
                int temp=l[j];
                l[j]=l[j+1];
                l[j+1]=temp;
            }  
        }      
    }

    cout<<l[0]<<endl<<l[1]<<endl<<l[2]<<endl<<l[3]<<endl<<l[4];
    return 0;
}