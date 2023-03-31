#include <iostream>
#include<vector>
using namespace std;

vector<int>* getPathHelper(int** edges,int n,int s_v,int e_v,bool* visited){
    if(n==0){
        return NULL;
    }
    visited[s_v]=1;
    if(s_v==e_v){
        vector<int>* path=new vector<int>();
        path->push_back(s_v);
        return path;
    }
    
    
    for(int i=0;i<n;i++){
        if(i==s_v){
            continue;
        }
        if(edges[s_v][i]==1 && !visited[i]){
        	//visited[i]=1;
            vector<int>* path=getPathHelper(edges,n,i,e_v,visited);
            if(path!=NULL){
                path->push_back(s_v);
                return path;
            }
            
        }
    }
    return NULL;
}

void getPath(int **edges, int v, int start, int end){
	bool *visited = new bool[v]();
    for(int i=0;i<v;i++){
        visited[i]=0;
    }
	vector<int>* path= getPathHelper(edges, v, start,end, visited);
	delete[] visited;
    if(path!=NULL){
    	for(int i=0;i<path->size();i++){
            cout<<path->at(i)<<" ";
        }    
    }
    
    return;
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
	int s_v,e_v;
    cin>>s_v>>e_v;
    
    getPath(edges,n,s_v,e_v);

    return 0;
}