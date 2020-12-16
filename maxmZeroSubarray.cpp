// Length of maximum subarray of sum zero

#include<bits/stdc++.h>
using namespace std;


int maxZeroSumLen(int arr[], int n) {  // O(N) time
    int max_len = 0;
    unordered_map<int, int> prefixSum_idx;
    int prefixSum = 0;
    for (int idx = 0; idx < n; idx++) {
        prefixSum += arr[idx];
        if (prefixSum_idx.find(prefixSum) == prefixSum_idx.end()) {
            prefixSum_idx[prefixSum] = idx;
        } else {
            int subArrayLen = idx - prefixSum_idx[prefixSum];
            if (subArrayLen > max_len)
                max_len = subArrayLen;
        }
    }
    return max_len;
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxZeroSumLen(arr, n) << endl;
    return 0;
}