// Given a 2D matrix, find the largest sub matrix with sum 0

#include<bits/stdc++.h>
using namespace std;

bool zeroSubArray(vector<int> arr, int n, int &start, int &end) {
    unordered_map<int, int> prefixSum;
    int curr_sum = 0;
    int maxlen = 0;
    prefixSum[0] = -1;
    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];
        if (prefixSum.find(curr_sum) != prefixSum.end()) {
            if (i - prefixSum[curr_sum] > maxlen) {
                start = prefixSum[curr_sum] + 1;
                end = i;
                maxlen = end - start + 1;
            }
        } else {
            prefixSum[curr_sum] = i;
        }
    }
    return maxlen != 0;
}

int largestZeroSubmatrix(vector<vector<int>> matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> temp;
    int finalLeft = 0, finalRight = 0, finalTop = 0, finalBottom = 0;
    int maxSize = 0;
    for (int left = 0; left < cols; left++) {
        temp = vector<int>(rows, 0);
        for (int right = left; right < cols; right++) {
            for (int i = 0; i < rows; i++) {
                temp[i] += matrix[i][right];
            }
            int currTop, currBottom;
            bool zeroPresent = zeroSubArray(temp, rows, currTop, currBottom);
            int size = (currBottom - currTop + 1) * (right - left + 1);
            if (zeroPresent && size > maxSize) {
                maxSize = size;
                finalLeft = left;
                finalRight = right;
                finalTop = currTop;
                finalBottom = currBottom;
            }
        }
    }
    return (finalRight - finalLeft + 1) * (finalBottom - finalTop + 1);
}

int main()
{
    vector<vector<int>> matrix = {{ 9, 7, 16, 5}, 
                                  { 1, -6, -7, 3}, 
                                  { 1, 8, 7, 9}, 
                                  { 7, -2, 0, 10}}; 
    cout << largestZeroSubmatrix(matrix) << endl; 
    return 0;
}