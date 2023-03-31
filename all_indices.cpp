#include<iostream>
using namespace std;

int* check(int a[],int size,int x,int out[]){
    static int i=0;
    if(size==0){
        return out;
    }
    return check(a+1,size-1,x,out);
    if(sizeof(out)!=0){
        i++;
            
    }
    
}

int main(){

    return 0;
}