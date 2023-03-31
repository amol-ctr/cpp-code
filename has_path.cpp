#include<iostream>
using namespace std;

bool hasPath(int** edges,int n,int s_v,int e_v,bool* visited){
    
    visited[s_v]=1;
    for(int i=0;i<n;i++){
        if(i==s_v){
            continue;
        }
        if(i==e_v && edges[s_v][i]==1){
            return true;
        }
        if(edges[s_v][i]==1){
            if(visited[i]){
                continue;
            }
            if(hasPath(edges,n,i,e_v,visited)==1){
                return true;
            }
        }
    }
    return false;
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

    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    cout<<hasPath(edges,n,0,4,visited);

    return 0;
}