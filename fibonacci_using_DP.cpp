#include<iostream>
using namespace std;

int fibo_helper(int n,int* ans){
    // BASE CASE
    if(n<=1){
        return n;
    }

    // PREVENTING RECALCULATION
    if(ans[n]!=-1){
        return ans[n];
    }

    //RECURSIVE CALLS IF ans[n] is -1
    int a=fibo_helper(n-1,ans);
    int b=fibo_helper(n-2,ans);

    // SAVING VALUE FOR FUTURE USE
    ans[n]=a+b;

    return ans[n];
}

// TIME COMPLEXITY USING MEMOIZATION(TOP-DOWN APPROACH) -> O(n)

int fibo_MEMOIZATION(int n){
    int* ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    } 
    return fibo_helper(n,ans);
}

int fibo_DP(int n){
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;

    for(int i=2;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}

// TIME COMPLEXITY USING DP -> O(n) .ALSO REDUCES SPACE COMPLEXITY COMPARED TO MEMOIZATION

int main(){

    cout<<fibo_DP(4);
    return 0;
}