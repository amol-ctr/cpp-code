#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){

    map<string,int>rollno;
    rollno["Rohit"]=1;
    rollno["Shyam"]=2;
    rollno["Vikas"]=3;
    rollno["Arun"]=4;

    // For inserting elements in a map using insert function
    rollno.insert({{"Ram",5},{"Suraj",6}});

    map<string,int> :: iterator i1;
    for(i1=rollno.begin();i1 !=rollno.end();i1++){
        cout<<(*i1).first<<"   "<<(*i1).second<<endl;
    }

    // Some important functions
    // rollno.size() --> Returns the size of map
    // rollno.max_size() --> Returns the max size which can be given to the Map
    // rollno.empty() --> Checks whether Map is empty or not,if yes it returns 1 ,else returns 0
    return 0;
}