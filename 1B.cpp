#include<bits/stdc++.h>
using namespace std;

int findPow(int num, int exp) {
    int count = 0;
    while (num % exp == 0 && num >= exp) {
        num /= exp;
        count++;
    }
    return count;
}

void printPath(vector<vector<int>> arr, int n) {
    string path = "";
    int i = n, j = n;
    while(i >= 1 && j > 0) {
        if (arr[i - 1][j] < arr[i][j - 1]) {
            path += "D";
            i--;
        } else {
            path += "R";
            j--;
        }
    }
    reverse(path.begin(), path.end());
    cout << arr[n][n] << endl
         << path << endl;
}

void solve(vector<vector<int>> &arr, int n) {
    vector<vector<int>> two(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> five(n + 1, vector<int>(n + 1, 0));
    five[0][0] = findPow(arr[0][0], 5);
    two[0][0] = findPow(arr[0][0], 2);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            cout << i << " " << j << endl;
            if (i == 0 || j == 0) {
                two[i][j] = five[i][j] = 0;
            } else {
                five[i][j] = min(five[i - 1][j], five[i][j - 1]) + findPow(arr[i - 1][j - 1], 5);
                two[i][j] = min(two[i - 1][j], two[i][j - 1]) + findPow(arr[i - 1][j - 1], 2);
            }
        }
    cout << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            cout << two[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            cout << five[i][j] << " ";
        cout << endl;
    }
    if (five[n][n] < two[n][n])
        printPath(five, n);
    else
        printPath(two, n);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> matrix[i][j];
    cout << 1 << endl;
    solve(matrix, n);
    return 0;
}