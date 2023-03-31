#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool charfound(vector<vector<char>> &board,int n,int m,int i,int j,int** visited,string s){
    if(s.size()==0){
        return true;
    }
    int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    for(int d=0;d<8;d++){
        int k=i+dir[d][0];
        int l=j+dir[d][1];
        if(k>=0 && l>=0 && k<n && l<m){
            if(board[k][l]==s[0] && !visited[k][l]){
                visited[k][l]=1;
                if(charfound(board,n,m,i,j,visited,s.substr(1))){
                    return true;
                }
                visited[k][l]=0;
            }
        }       
    }
    return false;
}

bool hasPath(vector<vector<char>> &board,int n,int m){
    string s="CODINGNINJA";

    int** visited=new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[m];
        for(int j=0;j<m;j++){
            visited[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==s[0] && !visited[i][j]){
                if(charfound(board,n,m,i,j,visited,s.substr(1))){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){

    return 0;
}