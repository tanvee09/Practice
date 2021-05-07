// Square Root Decomposition - Range Minimum Query

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

struct Query {
    int idx, l, r, lb;
};

bool comparator(Query a, Query b) {
    return (a.lb < b.lb) ||
           (a.lb == b.lb && a.r < b.r);
}

int main()
{
    fast;

    int n;
    cin >> n;
    vector<int> arr(n);
    int b = sqrt(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int q;
    cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].lb = queries[i].l / b;
        queries[i].idx = i;
        
    }

    sort(queries.begin(), queries.end(), comparator);
    
    multiset<int> nums;
    vector<int> ans(q);

    int currL = 0, currR = -1;

    for (Query query : queries) {
        int L = query.l, R = query.r;
        while (R > currR) {
            nums.insert(arr[++currR]);
        }
        while (L < currL) {
            nums.insert(arr[--currL]);
        }
        while (R < currR) {
            nums.erase(nums.find(arr[currR--]));
        }
        while (L > currL) {
            nums.erase(nums.find(arr[currL++]));
        }
        ans[query.idx] = *(nums.begin());
    }
    for (int i = 0; i < q; i++) cout << ans[i] << endl;

    return 0;
}