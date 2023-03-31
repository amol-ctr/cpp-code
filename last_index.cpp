#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x){

    if (size == 0)
    {
      return -1;
    }
    int answer = lastIndex(input + 1, size - 1, x);

    if (answer != -1)
    {
      return answer + 1;
    }

    if (input[0] == x)
    {
      return 0;
    }
    else
    {
      return -1;
    }
}
int main(){

    int a[]={5,5,6,5,6};
    cout<<lastIndex(a,5,6)<<endl;
    return 0;
}