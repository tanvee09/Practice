// Given heights of n different buildings, r ropes, b bricks, will I be able to reach last building from first building
// Nothing needed to go down, rope can climb any height, 1 brick can climb 1 unit of height

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int heights[], int n, int ropes, int bricks) {
    set<int> heightDiff;
    for (int i = 1; i < n; i++) {
        if (heights[i] - heights[i - 1] > 0)
            heightDiff.insert(heights[i] - heights[i - 1]);
    }
    if (ropes >= heightDiff.size())
        return true;
    auto diff = heightDiff.begin();
    for (int i = 0; i < heightDiff.size() - ropes; i++) {
        bricks-= *diff;
        diff++;
    }
    return bricks >= 0;
}

int main()
{
    int n = 10, r = 5, b = 20;
    int heights[10] = {2, 5, 3, 7, 9, 10, 25, 18, 20, 30};
    cout << isPossible(heights, n, r, b) << endl;
    return 0;
}