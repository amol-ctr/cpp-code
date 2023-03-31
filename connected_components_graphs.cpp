#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> connectedComponents(int** edges,int n,int s_v,vector<int>&visited,vector<int>& smallans){
   
	visited[s_v]=1;
    smallans.push_back(s_v);
    for(int i=0;i<n;i++){
        if(i==s_v){
            continue;
        }
        if(edges[s_v][i]==1 && !visited[i]){
            visited[i]=1;
             connectedComponents(edges,n,i,visited,smallans);
        }
    }
    return smallans;
}


void allconnectedcomponents(int ** edges,int n){
   vector<int>visited(n,0);
    vector<vector<int>> ans;
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<int> smallans1;
            vector<int> smallans=connectedComponents(edges,n,i,visited,smallans1);
            if(!smallans.empty())
            {
            	ans.push_back(smallans);        
            }
        }
    }
    
    if(!ans.empty()){
    	for(int i=0;i<ans.size();i++){
            vector<int> smallans=ans[i];
            sort(smallans.begin(),smallans.end());
            for(int j=0;j<smallans.size();j++){
                cout<<smallans[j]<<" ";
            }
            cout<<endl;
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
    
    allconnectedcomponents(edges,n);
}