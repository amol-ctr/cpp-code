#include<iostream>
#include<cmath>
using namespace std;


class simplecal{

    protected:
        int a,b;
        string op;

    public:
        void numbers(int n1,int n2){
            a=n1;
            b=n2;
        }

        void operation(){
            string o;
            cout<<"enter any of four operations +,-,*,/  "<<endl;
            cin>>o;
            op=o;
        }

        void displayresult(){
            if(op=="+")
            {
               cout<<a+b<<endl;
            }

            else if (op=="-")
            {
               cout<<a-b<<endl;
            }

            else if (op=="*")
            {
               cout<<a*b<<endl;
            }
            
            else if (op=="/")
            {
               cout<<a/b<<endl;
            }

            else
            {
                cout<<"incorrect operator chosen"<<endl;
            }
            
        }
};

class scientific_cal{

    protected:
        string ope;
        int a1;

    public:

        void num(int n){
            a1=n;
        }
        void operate(){
            string o1;
            cout<<"enter any of four strings i.e.  power,log,exponential,underroot"<<endl;
            cin>>o1;
            ope=o1;
        }

        void display(){
            if (ope=="power")
            {
                int exp;
                cout<<"enter the exponent "<<endl;
                cin>>exp;
                cout<<pow(a1,exp)<<endl;
            }
            else if (ope=="log")
            {
               cout<<log(a1)<<endl;
            }

            else if (ope=="underroot")
            {
               cout<<sqrt(a1)<<endl;
            }

            else if (ope=="exponential")
            {
               cout<<exp(a1)<<endl;
            }
            else
            {
                cout<<"incorrect choice"<<endl;
            }
            
        }
};

class hybridcal: public simplecal, public scientific_cal{


};

int main(){

/* simplecal c1;
    c1.numbers(4,2);
    c1.operation();
    c1.displayresult();

    scientific_cal c2;
    c2.num(5);
    c2.operate();
    c2.display();
*/

    hybridcal c;
    c.numbers(3,4);
    c.operation();
    c.displayresult();
    c.num(5);
    c.operate();
    c.display();
    return 0;
}