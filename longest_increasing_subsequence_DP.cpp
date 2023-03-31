#include<iostream>
using namespace std;

int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here

        int *output = new int[n];
        int res = 0;

        for (int i = 0; i < n; i++) {
          output[i] = 1;
        }

        for (int i = 1; i < n; i++) {
          int ans = 1;
          for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
              output[i] = max(output[j] + 1, output[i]);
            }
          }
        }

        for (int i = 0; i < n; i++) {
          res = max(output[i], res);
        }
        return res;
}

int main(){

    return 0;
}