#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

void dijkstra_algorithm(int** edges,int n,bool* visited,int* distances,int s_v){
    visited[s_v]=1;
    cout<<s_v<<" "<<distances[s_v]<<endl;
    int min=INT_MAX;
    int min_vertex=-1;
    for(int i=0;i<n;i++){
        if(edges[s_v][i]>0 && !visited[i]){
            int distance=distances[s_v]+edges[s_v][i];
            if(distance<distances[i]){
                distances[i]=distance;
            }
        }
        if(distances[i]<min && !visited[i]){
            min=distances[i];
            min_vertex=i;
        }
    }
    if(min_vertex!=-1){
        dijkstra_algorithm(edges,n,visited,distances,min_vertex);
    }
    
}

// TIME COMPLEXITY OF DIJKSTRA ALGORITHM -> O(N^2)

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
        int s_v,e_v,weight;
        cin>>s_v>>e_v>>weight;
        edges[s_v][e_v]=weight;
        edges[e_v][s_v]=weight;

    }

    bool* visited=new bool[n];
    int* distances=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
        distances[i]=INT_MAX;
    }
    distances[0]=0;

    dijkstra_algorithm(edges,n,visited,distances,0);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] distances;
    delete[] visited;

    return 0;
}