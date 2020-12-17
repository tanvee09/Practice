// Calculate a^b where a and b are integers

#include<bits/stdc++.h>
using namespace std;

float powerIter(float a, int b) {
    float result = 1;
    if (b < 0) {
        a = 1.0 / a;
        b = -b;
    }
    while (b) {
        if (b % 2 == 1) {
            result *= a;
        }
        b = b / 2;
        a = a * a;
    }
    return result;
}

float powerRec(int a, int b) {
    if (b == 0)
        return 1;
    float perfecrSqRoot = powerRec(a, b / 2);
    if (b % 2 == 0)
        return perfecrSqRoot * perfecrSqRoot;
    else if (b < 0)
        return perfecrSqRoot * perfecrSqRoot / a;
    else
        return perfecrSqRoot * perfecrSqRoot * a;
}

int main()
{
    cout << powerIter(3, 5) << " " << powerRec(3, 5) << endl;
    cout << powerIter(2, -4) << " " << powerRec(2, -4) << endl;
    return 0;
}