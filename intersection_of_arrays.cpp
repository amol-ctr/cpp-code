#include<iostream>
using namespace std;

void merge(int *part1, int size1, int *part2, int size2, int*output, int n)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<size1&&j<size2)
    {
        if(part1[i]<part2[j])
        {
            output[k++]=part1[i++];
        }
        else
        {
            output[k++]=part2[j++];
        }
    }
    while(j<size2)
    {
        output[k++]=part2[j++];
    }
    while(i<size1)
    {
        output[k++]=part1[i++];
    }
}
void mergeSort(int arr[], int size)
{
	if(size==1)
	{
		return;
	}
    int *part1=new int [size/2];
    int size1=size/2;
    int *part2=new int [size-size/2];
    int size2=size-size/2;
    for(int i=0; i<size1; i++)
    {
        part1[i]=arr[i];
    }
    int k=0;
    for(int i=size1; i<size; i++)
    {
        part2[k++]=arr[i];
    }
    mergeSort(part1, size1);
    mergeSort(part2, size2);
    merge(part1, size1, part2, size2, arr, size);
}
void intersection(int *arr1, int *arr2, int n, int m) 
{
    if(n==0||m==0){
        return;
    }
	mergeSort(arr1,n);
	mergeSort(arr2,m);
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            cout<<arr2[j]<<" ";
			i++;
            j++;
        }
    }
} 

int pairSum(int *arr, int n, int num)
{   
    if(n==0){
        return 0;
    }
    mergeSort(arr,n);
    static int count=0; 
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]+arr[j]>num){
            j--;
        }
        if(arr[i]+arr[j]<num){
            i++;
        }
        if(arr[i]+arr[j]==num){
            int c1=0,c2=0;
                for(int x=i;x<=j;x++)
                {
                    if(arr[x]==arr[i])
                        c1++;
                    else
                        break;
                }
                for(int x=j;x>=i;x--)
                {
                    if(arr[x]==arr[j])
                        c2++;
                    else
                        break;
                }
                int c=c1*c2;
                // when all elements are repeated
                if(arr[i]==arr[j])
                {
                    c=((j-i+1)*(j-i))/2;
                }
                
                    count+=c;
                  
                i+=c1;
                j-=c2;
        }
    }
    return count;
}
int main(){
    int arr1[]={1,3,2,2,1,3};
    int arr2[]={2,4,3};
    cout<<pairSum(arr1,6,4);
    // intersection(arr1,arr2,5,3);
    return 0;
}