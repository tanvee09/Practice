// Can multiply by 2, multiply by 3, add 1
// Find minimum number of steps to reach n

#include<bits/stdc++.h>
using namespace std;

int countMinSteps(int n) {
    int minSteps[n + 1];
    for (int i = 0; i <= n; i++)
        minSteps[i] = INT_MAX;
    minSteps[0] = minSteps[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (i + 1 <= n)
            minSteps[i + 1] = min(minSteps[i + 1], minSteps[i] + 1);
        if (2 * i <= n)
            minSteps[2 * i] = min(minSteps[2 * i], minSteps[i] + 1);
        if (3 * i <= n)
            minSteps[3 * i] = min(minSteps[3 * i], minSteps[i] + 1);
    }

    return minSteps[n];
}

int main()
{
    cout << countMinSteps(7) << endl;
    return 0;
}