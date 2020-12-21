// Given the price of stocks, find the maximum profit you can make

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int n) {
    int min_so_far = arr[0];
    int max_profit_so_far = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_so_far)
            min_so_far = arr[i];
        else if (arr[i] - min_so_far > max_profit_so_far)
            max_profit_so_far = arr[i] - min_so_far;
    }
    return max_profit_so_far;
}

int main()
{
    int arr[] = {20, 30, 10, 50, 60, 90, 70};
    int n = 7;
    cout << maxProfit(arr, n) << endl;
    return 0;
}