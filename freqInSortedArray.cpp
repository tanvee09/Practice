#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int elt) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == elt)
            return mid;
        else if (arr[mid] > elt)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

int countOccurances(int arr[], int n, int elt) {
    int idx = binarySearch(arr, n, elt);
    if (idx == -1)
        return 0;
    int freq = 1;
    int i = idx - 1;
    while (i >= 0 && arr[i--] == elt) {
        freq++;
    }
    i = idx + 1;
    while (i < n && arr[i++] == elt) {
        freq++;
    }
    return freq;
}

int main()
{
    int n = 10;
    int arr[] = {1, 3, 3, 3, 3, 5, 6, 7, 7, 8};
    cout << countOccurances(arr, n, 3) << endl;
    return 0;
}