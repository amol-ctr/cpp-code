#include<iostream>
using namespace std;


// ---->  USING RECURSION

int LCS_recursion(string s,string t){
    if(s.length()==0 || t.length()==0){
        return 0;
    }

    if(s[0]==t[0]){
        return 1+LCS_recursion(s.substr(1),t.substr(1));
    }

    else{

        int a=LCS_recursion(s.substr(1),t);
        int b=LCS_recursion(s,t.substr(1));
  //    int c=LCS_recursion(s.substr(1),t.substr(1));   // redundant call not required
        return max(a,b);
    }
}

// TIME COMPLEXITY(VERY HIGH)---> O(2^n)


//---->USING MEMOIZATION

int helper(string s,string s1,int** output){

    if(s.length()==0 || s1.length()==0){
        return 0;
    }

    int m=s.length();
    int n=s1.length();
    int ans;

    if(output[m][n]!=-1){
        return output[m][n];
    }

    if(s[0]==s1[0]){
        output[m][n]= 1+helper(s.substr(1),s1.substr(1),output);
        return output[m][n];
    }

    else{
        int a=helper(s.substr(1),s1,output);
        int b=helper(s,s1.substr(1),output);
        int c=helper(s.substr(1),s1.substr(1),output);
        ans=max(a,max(b,c));
    }

    output[m][n]=ans;
    return ans;

}

int LCS_memo(string s,string s1){
    int l1=s.length();
    int l2=s1.length();
    int** output=new int*[l1+1];
    for(int i=0;i<=l1;i++){
        output[i]=new int[l2+1];
        for(int j=0;j<=l2;j++){
            output[i][j]=-1;
        }
    }

    return helper(s,s1,output);
}

// --->TIME COMPLEXITY --> O(m*n) ,SPACE COMPLEXITY --> O(m*n)      (FOR MEMOIZATION)


// USING DP

int LCS_DP(string s,string s1){
    int m=s.length();
    int n=s1.length();
    int** ans=new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i]=new int[n+1];
    }

    for(int i=0;i<=m;i++){
        ans[i][0]=0;
    }
    for(int j=1;j<=n;j++){
        ans[0][j]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==s1[n-j]){
                ans[i][j]=1+ans[i-1][j-1];
            }
            else{
                int a=ans[i][j-1];
                int b=ans[i-1][j];
                int c=ans[i-1][j-1];
                ans[i][j]=max(a,max(b,c));
            }
        }
    }

    return ans[m][n];
}

int main(){
    string s="abcd";
    string s1="badce";
    cout<<LCS_recursion(s,s1)<<endl;
    cout<<LCS_memo(s,s1)<<endl;
    cout<<LCS_DP(s,s1)<<endl;
    return 0;
}