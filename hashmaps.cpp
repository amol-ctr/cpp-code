#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int* a,int size){
    vector<int> output;
    unordered_map<int,bool> seen;
    for(int i=0;i<size;i++){
        if(seen.count(a[i])==1){ // THIS CONDITION STATES WHENEVER THERE ARE DUPLICATE a[i] ,IT 
                                // SKIPS THAT ITERATION
            continue;
        }
        seen[a[i]]=true;
        output.push_back(a[i]);
    }
    return output;
}

int getPairsWithDifferenceK(int *arr, int n, int k) {
    unordered_map<int, int> freq; 
    int pairCount = 0; 
    for (int i = 0; i < n; i++) { 
        
        int complement = arr[i] + k; 
        pairCount += freq[complement]; 
        
        if (k != 0) { 
            complement = arr[i] - k; 
            pairCount += freq[complement]; 
        } 
        freq[arr[i]]++; 
    } 
    return pairCount; 
}

int highestFrequency(int arr[], int n) {
    // Write your code here

    unordered_map<int,int> frequency;
    int count=0;
   
    for(int i=0;i<n;i++){
        if(frequency.count(arr[i])==1){
            frequency[arr[i]]++;
        }
        else{
            frequency[arr[i]]=1;
        }
        if(count<frequency[arr[i]]){
            count=frequency[arr[i]];
        }
    }
    
    int max;
    for(int i=0;i<n;i++){
        if(frequency[arr[i]]==count){
            max=arr[i];
            break;
        }
    } 
    return max;
}

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    if(n==0 || m==0){
        return;
    }
    unordered_map<int,int> map1;
    for(int i=0;i<n;i++){
        if(map1.count(arr1[i])==0){
            map1[arr1[i]]=1;
        }
        else{
            map1[arr1[i]]++;
        }
        
    }
    for(int j=0;j<m;j++){
        if(map1.count(arr2[j])==1){
            cout<<arr2[j]<<endl;
            if(map1[arr2[j]]==1){
                map1.erase(arr2[j]);
                continue;
            }
            map1[arr2[j]]--;
        }
    }
}

int pairSum(int *arr, int n) {
	
    if(n==0 || n==1){
        return 0;
    }
    int count=0;
    unordered_map<int,int> numfreq;
    for(int i=0;i<n;i++){
        
        if(numfreq.find(-arr[i])!=numfreq.end()){
            count+=numfreq[-arr[i]];
        }
        
    	numfreq[arr[i]]++;
    }
    return count;
}

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map <int , bool> check;
    unordered_map<int ,int > index;
    for(int i=0;i<n;i++){
        check[arr[i]]=true;
        index[arr[i]]=i;
    }
    int current =arr[0] , si=arr[0] , length=0, maxlength=0 , start=0;
    for(int i=0;i<n;i++){
        current =arr[i];
        si=arr[i];
        while(check[current]!=false){
            check[current]=false;
            length++; current ++;
        }
        current =arr[i]-1;
        while(check[current]!=false){
            check[current]=false;
            length++; current--; si--;
        }
        if(length>maxlength){
            start=si;
            maxlength=length;
        }
        if(length==maxlength && index[arr[i]]<index[start] ){
            start=si;
            maxlength=length;
        }
        length=0;
    }
    vector<int> ans;
    ans.push_back(start);
    ans.push_back(start+maxlength-1);
    return ans;
}

int main(){
    unordered_map<int,int> seen;
    seen[5]=2;
    seen[5]=3;
    cout<<-seen[5];
    return 0;
}