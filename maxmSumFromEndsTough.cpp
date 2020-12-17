// Given an array A and a value k, and an array B of length k
// find maximum sum of k elements extracted from the ends of A multiplied by elements of B in the order they are extracted

#include<bits/stdc++.h>
using namespace std;

int findMaxSum(int arr[], int b[], int n, int k) {
    int sum = 0, idx = 0;
    int left = 0, right = n - 1;
    while (k > 0 && left <= right) {
        if (k == 1) {
            sum += b[idx] * max(arr[left], arr[right]);
            k--;
            idx++;
        } else {
            if (arr[left] > arr[right] && arr[left + 1] > arr[right]) {
                sum += max(arr[left], arr[left + 1]) * max(b[idx], b[idx + 1]);
                sum += min(arr[left], arr[left + 1]) * min(b[idx], b[idx + 1]);
                left += 2;
            } else if (arr[left] > arr[right] && arr[right - 1] > arr[left]) {
                sum += max(arr[right], arr[right - 1]) * max(b[idx], b[idx + 1]);
                sum += min(arr[right], arr[right - 1]) * min(b[idx], b[idx + 1]);
                right -= 2;
            } else {
                sum += max(arr[left], arr[right]) * max(b[idx], b[idx + 1]);
                sum += min(arr[left], arr[right]) * min(b[idx], b[idx + 1]);
                left++;
                right--;
            }
            k -= 2;
            idx += 2;
        }
        // cout << left << " " << right << " " << sum << endl;
    }
    return sum;
}

int main()
{
    int n = 9, k = 3;
    int arr[9] = {9, 8, 4, 9, 3, 5, 2, 6, 7};
    int b[3] = {1, 2, 3};
    cout << findMaxSum(arr, b, n, k) << endl;
    return 0;
}