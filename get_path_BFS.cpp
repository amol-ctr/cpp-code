#include <iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;

void getPath(int **edges, int n, int s_v, int e_v,bool* visited){
	map<int,int> m1;
    vector<int>* path=new vector<int>();
	queue<int> pendingVertices;
    pendingVertices.push(s_v);
    visited[s_v]=1;
    while(!pendingVertices.empty()){
        int c_v=pendingVertices.front();  
        visited[c_v]=1;
        for(int i=0;i<n;i++){
            if(i==c_v){
                continue;
            }
            if(c_v==e_v){
                int i=c_v;
                while(i!=s_v){
                    path->push_back(i);
                    i=m1[i];
                }
                path->push_back(s_v);
    			break;
            }
            if(edges[c_v][i]==1 && !visited[i]){
                m1[i]=c_v;
                visited[i]=1;
				pendingVertices.push(i);
            }
        }
        pendingVertices.pop();
    }
    if(path!=NULL){
        for(int i=0;i<path->size();i++){
            cout<<path->at(i)<<" ";
        }  
    }
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
    
    getPath(edges,n,s_v,e_v,visited);
	delete[] visited;
    
    return 0;
}