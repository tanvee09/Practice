// minm of given range

#include<bits/stdc++.h>
using namespace std;

#define int long long

class SegTree {
private:
    int size;
    vector<int> mins;
public:
    SegTree(int n) {
        size = 1;
        while (size < n) { size *= 2; }
        mins.assign(2 * size, INT_MAX);
    }

    void build(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size())
                mins[x] = arr[lx];
            return;
        }
        int mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mins[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else 
            set(i, v, 2 * x + 2, mid, rx);
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int minm(int l, int r, int x, int lx, int rx) {
        if (r <= lx || l >= rx) return INT_MAX;
        if (l <= lx && r >= rx) return mins[x];
        int mid = (lx + rx) / 2;
        return min(minm(l, r, 2 * x + 1, lx, mid), minm(l, r, 2 * x + 2, mid, rx));
    }

    int minm(int l, int r) {
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
            cout << st.minm(l, r) << endl;
        }
    }

    return 0;
}