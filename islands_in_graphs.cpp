#include<iostream>
using namespace std;

void connected(int ** edges,int n,int s_v,bool* visited){
    if(n==0){
        return;
    }
    visited[s_v]=1;
    for(int i=0;i<n;i++){
        if(i==s_v){
            continue;
        }
        if(edges[s_v][i]==1 && !visited[i]){
            visited[i]=1;
            connected(edges,n,i,visited);
        }
    }
}

int allconnectedcomponents(int ** edges,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            connected(edges,n,i,visited);
            count++;
        }
    }
    return count;
}    
int main(){

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
    
    cout<<allconnectedcomponents(edges,n);
    return 0;
}