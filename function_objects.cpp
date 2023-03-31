#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;
int main(){

    // Function Objects (Functor) : A function wrapped in a class so that it is available like an object
    int arr[] = {1, 73, 4, 2, 54, 7};
    
    // sort(arr,arr+5);  --> It sorts first 5 elements in ascending order

    // here function object is used as a third parameter
    sort( arr, arr+6, greater< int >( )); // greater<int> is used to sort array in descending order

    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}