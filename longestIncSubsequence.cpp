// Find longest increasing subsequence

#include<bits/stdc++.h>
using namespace std;

int longestIncSubsequence(int arr[], int n) {
    int lis[n];
    lis[0] = 1;
    int maxlen = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
            maxlen = max(maxlen, lis[i]);
        }
    }
    return maxlen;
}

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60}; 
    int n = 8;
    cout << longestIncSubsequence(arr, n) << endl;
    return 0;
}