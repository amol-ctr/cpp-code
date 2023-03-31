#include<iostream>
using namespace std;

class complex{

    int a;
    int b;

    public:

        void setcomp(int n1,int n2){
            a=n1;
            b=n2;
        }

        void prtcomp(){
            cout<<"the value of complex is: "<<a<<" + "<<b<<"i"<<endl;
        }

        void sumcomp(complex v1,complex v2);
};  

void complex :: sumcomp(complex v1,complex v2){
            a=v1.a + v2.a;
            b=v1.b + v2.b;
        }

class employee{
    int id;
    int salary;

    public:

        void setid(){

            cout<<"enter the id of employee: ";
            cin>>id;
        }

        void setsalary(){

            cout<<"enter the salary of employee: ";
            cin>>salary;
        }

        void getid(){
             
             cout<<"the id of employee is: "<<id<<endl;

        }

        void getsalary(){     
             cout<<"the salary of employee is: "<<salary<<endl;
        }

};

int main(){

    complex a1,a2,a3;
    a1.setcomp(1,2);
    a1.prtcomp();

    a2.setcomp(3,4);
    a2.prtcomp();

    a3.sumcomp(a1,a2);
   
    a3.prtcomp(); 


    employee listid[4],listsalary[4];

    for(int i=0; i<4;i++){


        listid[i].setid();
        listsalary[i].setsalary();

    }

    for(int i=0; i<4;i++){


        listid[i].getid();
        listsalary[i].getsalary();

    }     


    return 0;
}