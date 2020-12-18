// Given a matrix, 1 representing land, 0 representing water. Count number of islands

#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> matrix, vector<vector<bool>> &visited, int i, int j, int n) {
    if (i >= n || i < 0 || j >= n || j < 0 || !matrix[i][j] || visited[i][j])
        return;
    visited[i][j] = true;
    helper(matrix, visited, i + 1, j, n);
    helper(matrix, visited, i - 1, j, n);
    helper(matrix, visited, i, j + 1, n);
    helper(matrix, visited, i, j - 1, n);
    helper(matrix, visited, i + 1, j + 1, n);
    helper(matrix, visited, i + 1, j - 1, n);
    helper(matrix, visited, i - 1, j + 1, n);
    helper(matrix, visited, i - 1, j - 1, n);
}

int countIslands(vector<vector<int>> matrix) {
    int n = matrix.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] && !visited[i][j]) {
                helper(matrix, visited, i, j, n);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 0, 0, 0}, 
                                  {0, 1, 0, 0, 1}, 
                                  {1, 0, 0, 1, 1}, 
                                  {0, 0, 0, 0, 0}, 
                                  {1, 0, 1, 0, 1}};
    cout << countIslands(matrix) << endl;
    return 0;
}