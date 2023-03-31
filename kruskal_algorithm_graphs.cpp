#include <iostream>
#include<algorithm>

using namespace std;

class edge{
    public:
    int source;
    int destination;
    int weight;		//WEIGHT OF AN EDGE
    
};

bool comparator(edge a,edge b){
        return a.weight<=b.weight;
    }

void MST(edge* input,int* parent,int n,int e,edge* output){
    
    sort(input,input+e,comparator);
    
	int count=0;
    for(int i=0;i<e;i++){
        if(count==n-1){
            break;
        }
        edge currentedge=input[i];
        int f_v=currentedge.source;
        while(f_v!=parent[f_v]){
            f_v=parent[f_v];
        }
        
        int s_v=currentedge.destination;
        while(s_v!=parent[s_v]){
            s_v=parent[s_v];
        }
        
        if(f_v==s_v){
            continue;
        }
        
        output[count]=input[i];
        parent[f_v]=s_v;
        count++;
    }
}

int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    
    edge* input=new edge[e];
    edge* output=new edge[n-1];
    for(int i=0;i<e;i++){
        int f_v,s_v,weight1;
        cin>>f_v>>s_v>>weight1;
		edge e1;
        e1.source=f_v;
        e1.destination=s_v;
        e1.weight=weight1;
        input[i]=e1;
    }
    
    int* parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    
    MST(input,parent,n,e,output);
    
    for(int i=0;i<n-1;i++){
        if(output[i].source > output[i].destination)
            swap(output[i].source, output[i].destination);

        cout << output[i].source<<" "<< output[i].destination<<" "<< output[i].weight<<endl;
    }
    
    return 0;
}