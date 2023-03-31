#include<iostream>
using namespace std;

class employee{
    public:
        int id;
        int salary;
        employee(){
            id=1;
            salary=34;
        }

        employee(int inpid , int empsalary=34){
            id=inpid;
            salary=empsalary;
        }

};

class programmer: public employee{
    public:
        programmer(){
            id=1;
            salary=34;
            cout<<id<<endl<<salary<<endl;
        }

        programmer(int inpid,int empsalary=34){
            id=inpid;
            salary=empsalary;
            cout<<id<<endl<<salary<<endl;
        }
};
int main(){

    employee amol,harry(2),amit(2,35000);
    cout<<harry.salary<<endl;
    cout<<harry.id<<endl;
    cout<<amit.salary<<endl;
    cout<<amit.id<<endl;
    programmer amol1,harry1(2),amit1(10,70000);
    return 0;
}