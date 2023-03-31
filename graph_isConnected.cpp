#include <iostream>
using namespace std;

bool isConnected(int** edges,int n,int s_v,bool* visited){
    if(n==0){
        return true;
    }
    
    visited[s_v]=1;
    for(int i=0;i<n;i++){
        if(i==s_v){
            continue;
        }
        if(edges[s_v][i]==1){
            if(visited[i]==1){  // SO THAT WE DON'T VISIT THE SAME VERTEX AGAIN 
                continue;
            }
            isConnected(edges,n,i,visited);
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}

int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    
    if(isConnected(edges,n,0,visited)==1){
    	cout<<"true";
    }
    else{
        cout<<"false";
    }
	delete[] visited;
    
    return 0;
}