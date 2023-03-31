#include<iostream>
#include<fstream>

using namespace std;
int main(){

    string st1,st2;
    /*
    st1="hello how are you?";
    ofstream out("sample.txt");
    out<<st1;
    */

    ifstream in("sample.txt");

//  in>>st2;                     // for reading a single word
    
    while(in.eof()==0){
        getline(in , st2);          // for reading the complete line
        cout<<st2<<endl;
    }
    return 0;
}