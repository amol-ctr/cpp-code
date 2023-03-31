#include<iostream>
#include<vector>
using namespace std;

int found(vector<vector<int>> &cake,int n,int &i,int &j,int** visited){
    if(visited[i][j]){
        return 0;
    }
    visited[i][j]=1;
    int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
    int count=1;
    for(int d=0;d<4;d++){
        int k=i+dir[d][0];
        int l=j+dir[d][1];
        if(k>=0 && l>=0 && k<n && l<n){
            if(cake[k][l]==1){
                count+=found(cake,n,k,l,visited);   
            }
            
        }
    }
    return count;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    if(n==0){
        return false;
    }
    int biggest_piece=0;
    int** visited=new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[n];
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j]==1 && !visited[i][j]){
            	int count=found(cake,n,i,j,visited);
                if(count>biggest_piece){
                    biggest_piece=count;
                }
            }
        }
    }
	return biggest_piece;   
}