// minm and count of given range

#include<bits/stdc++.h>
using namespace std;

#define int long long

class SegTree {
private:
    int size;
    vector<pair<int, int>> mins;
public:
    SegTree(int n) {
        size = 1;
        while (size < n) { size *= 2; }
        mins.assign(2 * size, {INT_MAX, 0});
    }

    pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return {a.first, a.second + b.second};
        } else if (a.first < b.first) {
            return a;
        } else {
            return b;
        }
    }

    void build(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size())
                mins[x] = {arr[lx], 1};
            return;
        }
        int mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        auto left = mins[2 * x + 1];
        auto right = mins[2 * x + 2];
        mins[x] = combine(left, right);
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mins[x] = {v, 1};
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else 
            set(i, v, 2 * x + 2, mid, rx);
        auto left = mins[2 * x + 1];
        auto right = mins[2 * x + 2];
        mins[x] = combine(left, right);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
        // for (auto i : mins) {
        //     cout << i.first << "," << i.second << " ";
        // }
        // cout << endl;
    }

    pair<int, int> minm(int l, int r, int x, int lx, int rx) {
        if (r <= lx || l >= rx) return {INT_MAX, 0};
        if (l <= lx && r >= rx) return mins[x];
        int mid = (lx + rx) / 2;
        auto left = minm(l, r, 2 * x + 1, lx, mid);
        auto right = minm(l, r, 2 * x + 2, mid, rx);
        return combine(left, right);
    }

    pair<int, int> minm(int l, int r) {
        return minm(l, r, 0, 0, size);
    }
};

int32_t main()
{
    int n, m;
    cin >> n >> m;
    SegTree st(n);

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    st.build(arr);

    while(m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            auto p = st.minm(l, r);
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}