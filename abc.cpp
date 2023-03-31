#include<iostream>
using namespace std;

int main(){

    char input[]={"abcd"};
    for(int k=0;input[k]!='\0';k++){
        for(int i=k;input[i]!='\0';i++){
            for(int j=k;j<=i ;j++){
                cout<<input[j];   
            }
            cout<<endl;
        }

    }
        
    return 0;
}