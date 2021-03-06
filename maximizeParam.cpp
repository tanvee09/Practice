// Given two arrays x and p(sorted), find i and j such that x[i] + x[j] + abs(p[i] - p[j]) is maximum

#include<bits/stdc++.h>
using namespace std;

int maximiseParam(int x[], int p[], int n) {
    int temp[n];
    int left = 0, right = n - 1;
    int maxm = INT_MIN;
    while (left < right) {
        maxm = max(maxm, x[left] + x[right] + p[right] - p[left]);
        if (x[left + 1] - p[left + 1] < x[right - 1] + p[right - 1]) {
            left++;
        } else {
            right--;
        }
    }
    return maxm;
}

int main()
{
    int n = 6;
    int p[] = {1, 4, 4, 5, 17, 18};
    int x[] = {8, 1, 2, 12, 8, 9};
    cout << maximiseParam(x, p, n) << endl;
    return 0;
}
