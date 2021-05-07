// https://codeforces.com/contest/1520/problem/G

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define rep(i,n) for (int i = 0; i < n; i++)

int n, m, w;
vector<vector<int>> city;
vector<vector<int>> distFromSrc, distFromDest;


bool isvalid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

vector<int> dx = {0,1,0,-1}, dy = {1,0,-1,0};

struct Node {
    int x, y, d;
};

void bfs(int sx, int sy) {
    vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
    queue<Node> q;
    q.push({sx,sy,0});
    visited[sx][sy] = true;
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();
        if (sx == 0 && sy == 0) distFromSrc[curr.x][curr.y] = curr.d;
        else if (sx == n - 1 && sy == m - 1) distFromDest[curr.x][curr.y] = curr.d;

        rep(i,4) {
            int x = curr.x + dx[i], y = curr.y + dy[i];
            if (isvalid(x,y) && !visited[x][y] && city[x][y] >= 0) {
                visited[x][y] = true;
                q.push({x,y,curr.d+w});
            }
        }
    }
}


int32_t main()
{
    fast;
    cin >> n >> m >> w;
    city = vector<vector<int>>(n, vector<int>(m));
    rep(i,n) rep(j,m) cin >> city[i][j];
    distFromSrc = distFromDest = vector<vector<int>>(n, vector<int>(m, LLONG_MAX));

    bfs(0,0);
    bfs(n-1,m-1);

    int ans = distFromSrc[n-1][m-1];

    Node closestToSrc = {0,0,LLONG_MAX}, closestToDest = {n-1,m-1,LLONG_MAX};

    rep(i,n) rep(j,m) {
        if (city[i][j] > 0) {
            if (distFromSrc[i][j] != LLONG_MAX && distFromSrc[i][j] + city[i][j] <= closestToSrc.d)
                closestToSrc = {i,j,distFromSrc[i][j] + city[i][j]};
            if (distFromDest[i][j] != LLONG_MAX && distFromDest[i][j] + city[i][j] <= closestToDest.d)
                closestToDest = {i,j,distFromDest[i][j] + city[i][j]};
        }
    }

    if (closestToDest.d < LLONG_MAX && closestToSrc.d < LLONG_MAX)
        ans = min(ans, closestToSrc.d + closestToDest.d);
    
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;

    return 0;
}