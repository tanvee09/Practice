// https://leetcode.com/problems/subarray-sum-equals-k/submissions/

#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) { // O(N) time
    int count = 0;
    unordered_map<int, int> prefixSum_idx;
    int prefixSum = 0;
    for (int idx = 0; idx < nums.size(); idx++) {
        prefixSum += nums[idx];
        if (prefixSum == k)
            count++;
        if (prefixSum_idx.find(prefixSum - k) != prefixSum_idx.end())
            count += prefixSum_idx[prefixSum - k];
        prefixSum_idx[prefixSum] += 1;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << endl;
}