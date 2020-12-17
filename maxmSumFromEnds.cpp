// Given an array and a value k, find maximum sum of k elements from the ends

#include<bits/stdc++.h>
using namespace std;

int maxmSumFromEnds(int arr[], int n, int k) {
    int front = 0, back = n - 1;
    if (k > n)
        return accumulate(arr, arr + n, 0);
    int sum = 0;
    while (k && front <= back) {
        if (arr[front] > arr[back]) {
            sum += arr[front++];
        } else {
            sum += arr[back--];
        }
        k--;
    }
    return sum;
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << maxmSumFromEnds(arr, n, k) << endl;
    return 0;
}