#include<iostream>
using namespace std;

bool is_sorted(int a[],int size){
    if(size==0 || size==1){
        return true;
    }
    if(a[0]>a[1]){
        return false;
    }
    else{
        return is_sorted(a+1,size-1); 
    }

}

int main(){
    int a[]={1,2,5,4};
    cout<<is_sorted(a,4)<<endl;

    return 0;
}