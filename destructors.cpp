#include<iostream>
using namespace std;

int count=0;
class num{
    public:
        num(){
            cout<<"this is the time when constructor is called"<<endl;
            count++;
            cout<<"this time constructor is called for object no. "<<count<<endl;
        }

        ~num(){
            cout<<"this the time when destructor is called for object no. "<<count<<endl;
            count--;
        }

};
int main(){

    cout<<"entering the constructor"<<endl;
    num n1;
    {
        cout<<"creating two objects"<<endl;
        num n2,n3;
        cout<<"exiting the block"<<endl;
    }
    cout<<"back to main loop"<<endl;
    return 0;
}