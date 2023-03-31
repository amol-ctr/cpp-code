#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class PriorityQueue{  // MIN HEAP IS FORMED BUT STORED IN THE FORM OF VECTOR/ARRAY
    vector<int> pq;
    public:
    PriorityQueue(){

    }

    bool isempty(){
        return pq.size()==0;
    }

    int getsize(){
        return pq.size();
    }

    int getMin(){
        if(isempty()){
            return NULL;
        }
        return pq[0];
    }

    void insert(int a){
        pq.push_back(a);
        int child_index=pq.size()-1;
        while(child_index!=0){
            int index_root=(child_index-1)/2;
            if(pq[index_root]>pq[child_index]){
                int temp=pq[index_root];
                pq[index_root]=pq[child_index];
                pq[child_index]=temp;
                child_index=index_root;
            }
            else{
                return;
            }
        }
        
    }


    int removeMin(){
        int min=pq[0];
        int leaf_index=pq.size()-1;
        // SWAPPING
        pq[0]=pq[leaf_index];
        pq[leaf_index]=min;
        pq.pop_back();

        int parent_index=0;
        while(parent_index<(pq.size()-1)){
            int left_child_index=2*parent_index+1;
            int right_child_index=2*parent_index+2;
            int min_index;
            if(left_child_index>=pq.size()){
                return min;
            }
            else if (right_child_index>=pq.size()){
                min_index=left_child_index;
                if(pq[parent_index]>pq[min_index]){
                    int temp=pq[parent_index];
                    pq[parent_index]=pq[min_index];
                    pq[min_index]=temp;
                }
                return min;
            }
            else{
                if(pq[left_child_index]>=pq[right_child_index]){
                     min_index=right_child_index;    
                }

                if(pq[left_child_index]<pq[right_child_index]){
                     min_index=left_child_index;    
                }

                if(pq[parent_index]>pq[min_index]){
                    int temp=pq[parent_index];
                    pq[parent_index]=pq[min_index];
                    pq[min_index]=temp;
                }
                else{
                    return min;
                }
                parent_index=min_index;
            }            

        }
        return min;
    }

};

class comp{
    public:
    bool operator()(int a,int b){
        return a>b;
    }
};

int main(){
    priority_queue<int,vector<int>,comp> pq;        // MIN HEAP AS NEW ELEMENT INSERTED WILL BE CHECKED IF IT 
    pq.push(15);                                    // IS BIGGER THAN PREVIOUS ELEMENTS 
    pq.push(6);
    pq.push(9);
    pq.push(12);
    pq.push(1);
    pq.push(3);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;
}