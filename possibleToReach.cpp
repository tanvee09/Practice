// Find if it is possible to reach (n-1, m-1) from (0, 0) in a nxm matrix
// Can move to adjacent cell only if value is less than equal to current value

#include<bits/stdc++.h>
using namespace std;

bool isPathPossible(vector<vector<int>> matrix, vector<vector<int>> visited, int n, int m, int i, int j) {
    if (i >= n || j >= m || i < 0 || j < 0 || visited[i][j])
        return false;
    if (i == n - 1 && j == m - 1)
        return true;
    visited[i][j] = true;
    if (i + 1 < n && matrix[i][j] >= matrix[i + 1][j] && isPathPossible(matrix, visited, n, m, i + 1, j))
            return true;
    if (i - 1 >= 0 && matrix[i][j] >= matrix[i - 1][j] && isPathPossible(matrix, visited, n, m, i - 1, j))
            return true;
    if (j + 1 < n && matrix[i][j] >= matrix[i][j + 1] && isPathPossible(matrix, visited, n, m, i, j + 1))
            return true;
    if (j - 1 >= 0 && matrix[i][j] >= matrix[i][j - 1] && isPathPossible(matrix, visited, n, m, i, j - 1))
            return true;
    visited[i][j] = false;
    return false;
}

bool isPathPossible2(vector<vector<int>> matrix, int m, int n) {
    vector<vector<bool>> isPossible(m, vector<bool>(n, false));
    isPossible[0][0] = true;
    for (int i = 1; i < m; i++)
        if (matrix[i][0] <= matrix[i - 1][0])
            isPossible[i][0] = isPossible[i - 1][0];
    for (int j = 1; j < n; j++)
        if (matrix[0][j] <= matrix[0][j - 1])
            isPossible[j][0] = isPossible[0][j - 1];
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++) {
            if ((matrix[i][j] <= matrix[i - 1][j] && isPossible[i - 1][j]) || (matrix[i][j] <= matrix[i][j - 1] && isPossible[i][j - 1]))
                isPossible[i][j] = true;
        }
    return isPossible[m - 1][n - 1];
}

int main()
{
    int n = 5, m = 4;
    vector<vector<int>> matrix = {{25, 25, 40, 22},
                                  {25, 25, 19, 18},
                                  {40, 40, 40, 14},
                                  {13, 12, 11, 10},
                                  { 9,  8,  7,  6}};
    vector<vector<int>> visited(n, vector<int>(m, false));
    cout << isPathPossible(matrix, visited, n, m, 0, 0) << endl;
    cout << isPathPossible2(matrix, n, m) << endl;
    return 0;
}