#include<iostream>
#include<queue>
using namespace std;

void heapsort(int arr[],int n){
    if(n==0){
        return;
    }
    int starting_index=1;
    while(starting_index<n){
        int parent_index;
        int child_index=starting_index;
        while(child_index!=0){
            parent_index=(child_index-1)/2;
            if(arr[parent_index]>arr[child_index]){
                int temp=arr[parent_index];
                arr[parent_index]=arr[child_index];
                arr[child_index]=temp;
            }
            else{
                break;
            }
            child_index=parent_index;
        }
        starting_index++;
    }

    int size=n;
    while(size>1){
        int temp=arr[size-1];
        arr[size-1]=arr[0];
        arr[0]=temp;

        size--;
        int parent_index=0;
        while(parent_index<(size-1)){
            int left_child_index=2*parent_index+1;
            int right_child_index=2*parent_index+2;
            int min_index;
            if(left_child_index>=size){
                break;
            }
            else if (right_child_index>=size){
                min_index=left_child_index;
                if(arr[parent_index]>arr[min_index]){
                    int temp=arr[parent_index];
                    arr[parent_index]=arr[min_index];
                    arr[min_index]=temp;
                }
                break;
            }
            else{
                if(arr[left_child_index]>=arr[right_child_index]){
                     min_index=right_child_index;    
                }

                if(arr[left_child_index]<arr[right_child_index]){
                     min_index=left_child_index;    
                }

                if(arr[parent_index]>arr[min_index]){
                    int temp=arr[parent_index];
                    arr[parent_index]=arr[min_index];
                    arr[min_index]=temp;
                }
                else{
                    break;
                }
                parent_index=min_index;
            }            

        }
    }
}

void kSortedArray(int input[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        input[j]=pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while(!pq.empty()){
        input[j]=pq.top();
        pq.pop();
        j++;
    }
}

vector<int> kSmallest(int arr[], int n, int k) {
    priority_queue<int> pq;
    vector<int>* min=new vector<int>();
    if(n==0){
        return *min;
    }
	for(int i=0;i<k;i++){    
        pq.push(arr[i]);
    }
    int j=k;
    while(j<n){
        if(arr[j]<pq.top()){
            pq.pop();
            pq.push(arr[j]);
        }
        j++;
    }
    while(!pq.empty()){
        min->push_back(pq.top());
        pq.pop();
    }
    return *min;
}

#include<queue>
vector<int> kLargest(int input[], int n, int k){
   
	priority_queue<int,vector<int>,greater<int>> pq;
    vector<int>* max=new vector<int>();
    if(n==0){
        return *max;
    }
	for(int i=0;i<k;i++){      
        pq.push(input[i]);
    }
    int j=k;
    while(j<n){
        if(input[j]>pq.top()){
            pq.pop();
            pq.push(input[j]);
        }
        j++;
    }
    while(!pq.empty()){
        max->push_back(pq.top());
        pq.pop();
    }
    return *max;
}

int kthLargest(int* arr, int n, int k) {
    priority_queue<int,vector<int>,greater<int>> pq;
    if(n==0){
        return NULL;
    }
	for(int i=0;i<k;i++){      
        pq.push(arr[i]);
    }
    int j=k;
    while(j<n){
        if(arr[j]>pq.top()){
            pq.pop();
            pq.push(arr[j]);
        }
        j++;
    }
    return pq.top();
}



bool isMaxHeap(int arr[], int n) {
    if(n==0 || n==1){
        return true;
    }
    int parent_index=0;

    int left_child_index=2*parent_index+1;
    int right_child_index=2*parent_index+2;

    if(right_child_index<n){
        if(arr[right_child_index]>arr[parent_index] ||arr[left_child_index]>arr[parent_index]){
            return false;
        }
    }
    else{
    	if(left_child_index<n){
            if(arr[left_child_index]>arr[parent_index]){
                return false;
            }
    	}
		else{
        	return true;     
        }
    }
    
    return isMaxHeap(arr+2*parent_index+1,n-(2*parent_index+1));
    return isMaxHeap(arr+2*parent_index+2,n-(2*parent_index+2));

}

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    vector<int> mergedarray;
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(int i=0;i<input.size();i++){
        for(int j=0;j<input[i]->size();j++){
            minheap.push(input[i]->at(j));
        }
    }
    while(!minheap.empty()){
        mergedarray.push_back(minheap.top());
        minheap.pop();
    }
    
    return mergedarray;
}

int buyTicket(int *arr, int n, int k) {
    if(n==0){
        return NULL;
    }
    static int count=0;
    priority_queue<int> maxheap;
    for(int i=0;i<n;i++){
        maxheap.push(arr[i]);
    }
    

}

int main(){

    int arr[]={10,15,6,4,5};
    //kSortedArray(arr,5,3);
    heapsort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}