#include<iostream>
#include<fstream>

using namespace std;
int main(){

    ofstream a1("sample60.txt");
    string s;
    cout<<"enter any text: "<<endl;
    cin>>s;
    a1<<s;
    a1.close();

    ifstream a2("sample.txt");
    string s_ ;
    getline(a2 , s_);
    cout<<s_ ;
    a2.close();

    return 0;
}