// Find if it is possible to reach (n-1, m-1) from (0, 0) in a nxm matrix
// Can move to adjacent cell only if value is less than equal to current value

#include<bits/stdc++.h>
using namespace std;

bool isPathPossible(vector<vector<int>> matrix, vector<vector<int>> visited, int n, int m, int i, int j) {
    if (i >= n || j >= m || visited[i][j])
        return false;
    if (i == n - 1 && j == m - 1)
        return true;
    if (i + 1 < n && matrix[i][j] >= matrix[i + 1][j] && isPathPossible(matrix, visited, n, m, i + 1, j)) {
        visited[i + 1][j] = true;
        return true;
    }
    if (i - 1 >= 0 && matrix[i][j] >= matrix[i - 1][j] && isPathPossible(matrix, visited, n, m, i - 1, j)) {
        visited[i - 1][j] = true;
        return true;
    }
    if (j + 1 < m && matrix[i][j] >= matrix[i][j + 1] && isPathPossible(matrix, visited, n, m, i, j + 1)) {
        visited[i][j + 1] = true;
        return true;
    }
    if (j - 1 >= 0 && matrix[i][j] >= matrix[i][j - 1] && isPathPossible(matrix, visited, n, m, i, j - 1)) {
        visited[i][j - 1] = true;
        return true;
    }
    return false;
}

int main()
{
    int n = 5, m = 4;
    vector<vector<int>> matrix = {{25, 24, 23, 22},
                                  {21, 20, 19, 18},
                                  {17, 16, 15, 14},
                                  {13, 12, 11, 10},
                                  { 9,  8,  7,  6}};
    vector<vector<int>> visited(n, vector<int>(m, false));
    cout << isPathPossible(matrix, visited, n, m, 0, 0) << endl;
    return 0;
}