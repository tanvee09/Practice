// https://leetcode.com/contest/weekly-contest-184/problems/number-of-ways-to-paint-n-3-grid/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int numOfWays(int n) {
    int twoColors = 6, threeColors = 6;
    for (int current = 1; current < n; current++) {
        int nextTwoColors = (((twoColors + twoColors) % mod + twoColors) % mod + (threeColors + threeColors) % mod) % mod;
        int nextThreeColors = ((twoColors + twoColors) % mod + (threeColors + threeColors) % mod) % mod;
        twoColors = nextTwoColors;
        threeColors = nextThreeColors;
    }
    return (twoColors % mod + threeColors % mod) % mod;
}

int main()
{
    int n;
    cin >> n;
    return 0;
}