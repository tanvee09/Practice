// https://codeforces.com/contest/1520/problem/F1

#include<bits/stdc++.h>
using namespace std;

int n, t, k;

int zeros(int l, int r, int sum) {
    return r - l + 1 - sum;
}

int getSum(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int sum;
    cin >> sum;
    return sum;
}

int findFirstOccurrence(int low, int high) {
 
    int result = -1;
 
    while (low <= high)
    {
        int mid = (low + high)/2;

        int midval = zeros(0,mid,getSum(1,mid+1));
        // cout << midval << endl;
        if (k == midval) {
            result = mid;
            high = mid - 1;
        } else if (k < midval) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main()
{
    cin >> n >> t;
    cin >> k;

    int result = findFirstOccurrence(0,n-1)+1;

    cout << "! " << result << endl;
    cout.flush();

    return 0;
}