#include<iostream>
#include<climits>
#include<math.h>
#include<vector>

using namespace std;

int minJumps(int nums[], int n){
        // Your code here
        int index=0;
        // int steps=0;
        int size=n;
        if(size==0 || size==1){
            return 0;
        }

        if((size==2 && nums[index]!=0) || nums[index]==size-1 || nums[index]>size-1){
            return 1;
        }

        if(nums[index]==0 && index!=size-1){
            return INT_MAX;
        }

        int increment=1;
        int min1=INT_MAX;
        while(increment<=nums[index]){
            int smallans=minJumps(nums+increment,size-increment)+1;
            min1=min(min1,smallans);
            increment++;
        }
        if(min1!=INT_MAX){
            
            return min1;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> *ans=new vector<int>();
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j){
                    continue;
                }
                if(nums[i]+nums[j]==target){
                    ans->push_back(i);
                    ans->push_back(j);
                    return *ans;
                }
            }
        }
        return *ans;
    }

int main(){
    int* arr=new int[5];
    arr[0]=2;
    arr[1]=3;
    arr[2]=1;
    arr[3]=1;
    arr[4]=4;

    int* arr1=new int[11];
    arr1[0]=1;
    arr1[1]=3;
    arr1[2]=5;
    arr1[3]=8;
    arr1[4]=9;
    arr1[5]=2;
    arr1[6]=6;
    arr1[7]=7;
    arr1[8]=6;
    arr1[9]=8;
    arr1[10]=9;

    // cout<<minJumps(arr,5);
    // cout<<minJumps(arr1,11);

    vector<int>* v1=new vector<int>();
    v1->push_back(1);
    v1->push_back(2);
    v1->push_back(3);
    v1->push_back(4);
    v1->push_back(5);
    vector<int> v2=twoSum(*v1,8);
    cout<<v2[0]<<" "<<v2[1]<<" ";
    return 0;
}