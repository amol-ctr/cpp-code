#include<iostream>
#include<vector>
using namespace std;

    void jump(vector<int>& v){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    jump(v);
    jump(&v[1]);
    return 0;
}