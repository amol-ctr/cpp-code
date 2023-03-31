#include<iostream>
using namespace std;

int lsearch(int arr[],int item){
    int r=0;
    for(int i=0;i<sizeof(arr);i++){
        if(item==arr[i]){
            r=1;
            return i;
            break;
        }
    }
    if(r==0){
        return sizeof(arr);
    }
}

int main(){
    int item;
    int a1[]={13,12,11,15,9};
    cout<<"enter the item you want to search in the list: ";
    cin>>item;

    int s=lsearch(a1,item);
    if(s==sizeof(a1)){
        cout<<"item not found"<<endl;
    }

    else{
        cout<<"item is found at "<<s+1<<" position and its value is "<<a1[s]<<endl;
    }
    return 0;
}