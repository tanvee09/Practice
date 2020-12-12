// https://leetcode.com/contest/weekly-contest-184/problems/queries-on-a-permutation-with-key/

/*
1. Create fenwick tree of size 2m with all zeroes
2. Add 1 to indices m + 1 to 2m
3. Save a map of index and number (q[i], q[i] + m)
4. For each query
    i.   Return the sum till index of query
    ii.  Update fenwick tree {Add -1 at index q[i], 1 at m - i}
    iii. Update hash map
*/

#include<bits/stdc++.h>
using namespace std;

class Fenwick {
    private:
        vector<int> array;

    public:
        Fenwick(int size) {
            int treeSize = 1;
            while(treeSize <= size) {
                treeSize *= 2;
            }
            array = vector<int>(treeSize, 0);
        }

        void add(int index, int value) {
            int size = array.size();
            while (index < size) {
                array[index] += value;
                index += index & -index;
            }
        }

        int sum(int index) {
            int result = 0;
            while (index > 0) {
                result += array[index];
                index -= index & -index;
            }
            return result;
        }
};

vector<int> processQueries(vector<int>& queries, int m) {
    Fenwick tree(2 * m + 1);
    unordered_map<int, int> indexMap;
    for (int i = 1; i <= m; i++) {
        tree.add(m + i, 1);
        indexMap[i] = m + i;
    }
    vector<int> result;
    int minEmptyIndex = m;
    for (int query : queries) {
        result.push_back(tree.sum(indexMap[query]) - 1);
        tree.add(minEmptyIndex, 1);
        tree.add(indexMap[query], -1);
        indexMap[query] = minEmptyIndex;
        minEmptyIndex--;
    }
    return result;
}

int main() 
{
    int n, m;
    cin >> n;
    vector<int> queries;
    for (int i = 0; i < n; i++) {
        int query;
        cin >> query;
        queries.push_back(query);
    }
    cin >> m;
    vector<int> results = processQueries(queries, m);
    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;
    return 0;
}