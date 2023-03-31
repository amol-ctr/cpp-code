#include<iostream>
#include<climits>
using namespace std;

// using Recursion

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	if(n==0 || maxWeight==0){
		return 0;
	}
	
	if(weights[n-1]>maxWeight){
    	return knapsack(weights , values , n - 1, maxWeight);
    }

	int x=knapsack(weights,values,n-1,maxWeight-weights[n-1])+values[n-1];
    int y = knapsack(weights , values , n - 1, maxWeight);
    return max(x, y);
}

// using memoization

int knapsack(int* weight, int* value, int n, int maxWeight,int** dp) {
	// Write your code here

	if (maxWeight == 0 || n == 0)
	{
		return 0;
	}
	if (dp[n][maxWeight] != -1)
	{
		return dp[n][maxWeight];
	}
	int ans;
	if (maxWeight < weight[0])
	{
		ans = knapsack(weight + 1, value + 1, n - 1, maxWeight, dp);
	}
	else
	{
		int a = knapsack(weight + 1, value + 1, n - 1, maxWeight - weight[0], dp) + value[0];
		int b = knapsack(weight + 1, value + 1, n - 1, maxWeight, dp);
		ans = max(a, b);
	}
	dp[n][maxWeight] = ans;
	return dp[n][maxWeight];
}

int knapsack(int *weight, int *value, int n, int maxWeight)
{
	int **dp = new int *[n + 1];
	for (int i = 0; i <= n; i++)
	{
		dp[i] = new int[maxWeight + 1];
		for (int j = 0; j <= maxWeight; j++)
		{
			dp[i][j] = -1;
		}
	}
	return knapsack(weight, value, n, maxWeight, dp);
}

// USING DP

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	int **dp = new int *[n + 1];
    
	for (int i = 0; i <= n; i++)
	{
		dp[i] = new int[maxWeight + 1];
	}

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 0;
	}

	for (int i = 0; i <= maxWeight; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= maxWeight; j++)
		{
			if (j < weights[i-1])
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - weights[i-1]] + values[i-1], dp[i - 1][j]);
			}
		}
	}
	return dp[n][maxWeight];
}

int main(){

    return 0;
}