// Maxm sum subarray

#include<bits/stdc++.h>
using namespace std;

// int maxmSumSubarray(int arr[], int n) {  // doesn't handle all negative elements
//     int max_till_now = 0, max_ending_here = 0;
//     int s = 0, start = 0, end = 0;
//     for (int i = 0; i < n; i++) {
//         max_ending_here += arr[i];
//         if (max_ending_here < 0) {
//             max_ending_here = 0;
//             s = i + 1;
//         } else if (max_ending_here >= max_till_now) {
//             max_till_now = max_ending_here;
//             start = s;
//             end = i;
//         }
//     }
//     cout << start << " " << end << endl;
//     return max_till_now;
// }

int maxmSumSubarray(int arr[], int n) {     // handles all negative elements
    int max_till_now = arr[0], max_ending_here = arr[0];
    int s = 0, end = 0, start = 0;
    for (int i = 0; i < n; i++) {
        max_ending_here = max_ending_here + arr[i];
        if (max_ending_here < arr[i]) {
            max_ending_here = arr[i];
            s = i;
        }
        if (max_ending_here > max_till_now) {
            end = i;
            start = s;
            max_till_now = max_ending_here;
        }
        // max_ending_here = max(arr[i], max_ending_here + arr[i]);
        // max_till_now = max(max_till_now, max_ending_here);
    }
    cout << start << " " << end << endl;
    return max_till_now;
}

int main()
{   
    int n = 10;
    int arr[] = {-3, -2, -1, 5, 6, -1, 8, -10, 5, 6};
    cout << maxmSumSubarray(arr, n) << endl;
    return 0;
}