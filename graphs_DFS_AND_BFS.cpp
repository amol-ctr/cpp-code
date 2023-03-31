#include<iostream>
#include<queue>
using namespace std;

void printDFS(int** edges,int n,int starting_vertex,int* visited){
    cout<<starting_vertex<<endl;
    visited[starting_vertex]=1;
    for(int i=0;i<n;i++){
        if(i==starting_vertex){
            continue;
        }
        if(edges[starting_vertex][i]==1){
            if(visited[i]==1){  // SO THAT WE DON'T VISIT THE SAME VERTEX AGAIN 
                continue;
            }
            printDFS(edges,n,i,visited);
        }
    }
}

void printBFS(int** edges,int n,int s_v,int* visited){
    queue<int>* pending_vertex=new queue<int>();
    pending_vertex->push(s_v);
    visited[s_v]=1;
    while(!pending_vertex->empty()){
        int c_v=pending_vertex->front();
        pending_vertex->pop();
        cout<<c_v<<" ";
        for(int i=0;i<n;i++){
            if(i==c_v){
                continue;
            }
            if(edges[c_v][i]==1 && visited[i]!=1){
            	pending_vertex->push(i); 
                visited[i]=1;   
            }
        }
    }
    delete[] visited;
}

void BFS(int** edges,int n){
    int* visited=new int[n];  // ARRAY FOR CLARIFYING WHICH VERTICES HAVE BEEN VISITED
    for(int i=0;i<n;i++){
        visited[i]=0;   // INITIALLY NO ELEMENT IS VISITED
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printBFS(edges,n,i,visited);
        }
    }
    delete[] visited;
}

void DFS(int** edges,int n){
    int* visited=new int[n];  // ARRAY FOR CLARIFYING WHICH VERTICES HAVE BEEN VISITED
    for(int i=0;i<n;i++){
        visited[i]=0;   // INITIALLY NO ELEMENT IS VISITED
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printDFS(edges,n,i,visited);
        }
    }
    delete[] visited;
}

int main(){
    int n;  // TOTAL NO. OF VERTICES
    int e;  // TOTAL NO. OF EDGES
    cin>>n>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;    // f means first vertex && s means second vertex
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    DFS(edges,n);

    // DELETING(CLEARING SPACE) ALL ARRAYS AND MATRICES
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges; 

    return 0;
}