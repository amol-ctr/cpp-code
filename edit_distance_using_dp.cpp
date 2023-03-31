#include<iostream>
using namespace std;

#include <string>
#include <climits>


// USING RECURSION
int editDistance(string s1, string s2) {

  if(s1.size()==0 || s2.size()==0){
    return max(s1.size(),s2.size());
  }

  if(s1[0]==s2[0]){
    return editDistance(s1.substr(1), s2.substr(1));
  }

  else{
    // add
    int x = editDistance(s1.substr(1), s2) + 1;

    // remove
    int y = editDistance(s1, s2.substr(1)) + 1;

    // replace
    int z = editDistance(s1.substr(1), s2.substr(1)) + 1;

    return min(x, min(y, z));
  }
  
}

// USING MEMOIZATION

int helper(string s1,string s2,int** output){
	int m = s1.size();
	int n = s2.size();
	if (s1.size() == 0 || s2.size() == 0) {
    	output[m][n]= max(s1.size(), s2.size());
		return output[m][n];
    }

    if (output[m][n] != -1) {
    	return output[m][n];
    }

    if (s1[0] == s2[0]) {
    	output[m][n]= helper(s1.substr(1), s2.substr(1),output);
		return output[m][n];
	}

    else {
		// add
		int x = helper(s1.substr(1), s2, output) + 1;

		// remove
		int y = helper(s1, s2.substr(1), output) + 1;

		// replace
		int z = helper(s1.substr(1), s2.substr(1), output) + 1;

		output[m][n]= min(x, min(y, z));
		return output[m][n];
		}
}

int editDistance_memo(string s1, string s2)
{
	//Write your code here

	int m=s1.size();
	int n=s2.size();

	int** output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			output[i][j]=-1;
		}
	}

	return helper(s1,s2,output);
}

// using DP 

int editDistance_DP(string s1,string s2){
    int m=s1.size();
    int n=s2.size();
    
    int** output=new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]=new int[n+1];
    }

    // filling 1st row
    for(int i=0;i<=m;i++){
        output[i][0]=i;
    }

    // filling 1st column
    for(int j=0;j<=m;j++){
        output[0][j]=j;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m-i]==s2[n-j]){
                output[i][j]=output[i-1][j-1];
            }
            else{
                //add
                int x=output[i-1][j];
                // remove
                int y=output[i][j-1];
                // replace
                int z=output[i-1][j-1];

                output[i][j]=min(x,min(y,z))+1;
            }
        }
    }

    return output[m][n];
}

int main(){

    return 0;
}