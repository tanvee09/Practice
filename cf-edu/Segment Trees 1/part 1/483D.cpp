// Interesting array https://codeforces.com/contest/483/problem/D

// Sum of given range

#include<bits/stdc++.h>
using namespace std;

#define int long long

class SegTree {
private:
    int size;
    vector<int> sums;
public:
    SegTree(int n) {
        size = 1;
        while (size < n) { size *= 2; }
        sums.assign(2 * size, 0);
    }

    void build(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size())
                sums[x] = arr[lx];
            return;
        }
        int mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else 
            set(i, v, 2 * x + 2, mid, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if (r <= lx || l >= rx) return 0;
        if (l <= lx && r >= rx) return sums[x];
        int mid = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, mid) + sum(l, r, 2 * x + 2, mid, rx);
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
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
            cout << st.sum(l, r) << endl;
        }
    }

    return 0;
}