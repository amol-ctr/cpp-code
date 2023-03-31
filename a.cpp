#include<iostream>
using namespace std;


int findNumber(int i){
    int sum=0;
    while(i!=0){
        sum=sum+i%10;
        i=i/10;
    }
    return sum;
}

void smallestNumber(int k){
    int j=1;
    while(1){
        if(findNumber(j)==k){

            cout<<j;
            break;
        }
        j++;
    }
}
int main(){

    int k;
    cin>>k;
    smallestNumber(k);

    return 0;
}