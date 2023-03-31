#include<iostream>
using namespace std;

class stu{

    int rno;
    public:

        int setdata(){
            cout<<"enter the roll no. of student: ";
            cin>>rno;
        }

        int getdata(){
            cout<<"the roll no. of student is: "<<rno<<endl;
            return rno;
        }

        friend stu fee(stu);
};

stu fee(stu amol){
    int fee;
    cout<<"enter the fee of student with roll no. "<<amol.getdata()<<" : ";
    cin>>fee;

    cout<<"the fees to be paid by student is: "<<fee<<endl;
}

int main(){

    stu a1;
    a1.setdata();
    
    fee(a1);
    

    return 0;
}