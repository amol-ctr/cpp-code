#include<iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here

        int *maxMoney = new int[n];
        maxMoney[0] = arr[0];
        if (n > 1) {
          maxMoney[1] = max(arr[1], maxMoney[0]);
        }
        for (int i = 2; i < n; i++) {
          // maxMoney[i-2] + arr[i] : In case we are including current
          // element maxMoney[i-1] : In case we are excluding current element
          maxMoney[i] = max(maxMoney[i - 2] + arr[i], maxMoney[i - 1]);
        }
        int result = maxMoney[n - 1];
        delete[] maxMoney;
        return result;
}

int main(){

    return 0;
}