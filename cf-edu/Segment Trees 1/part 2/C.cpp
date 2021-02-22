// first number greater than equal to given number

#include<bits/stdc++.h>
using namespace std;

#define int long long

class SegTree {
private:
    int size;
    int count;
    vector<int> maxs;
public:
    SegTree(int n) {
        size = 1;
        count = n;
        while (size < n) { size *= 2; }
        maxs.assign(2 * size, INT_MIN);
    }

    void build(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size())
                maxs[x] = arr[lx];
            return;
        }
        int mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        maxs[x] = max(maxs[2 * x + 1], maxs[2 * x + 2]);
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            maxs[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else 
            set(i, v, 2 * x + 2, mid, rx);
        maxs[x] = max(maxs[2 * x + 1], maxs[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int maxm(int l, int r, int x, int lx, int rx) {
        if (r <= lx || l >= rx) return INT_MAX;
        if (l <= lx && r >= rx) return maxs[x];
        int mid = (lx + rx) / 2;
        return max(maxm(l, r, 2 * x + 1, lx, mid), maxm(l, r, 2 * x + 2, mid, rx));
    }

    int maxm(int l, int r) {
        return maxm(l, r, 0, 0, size);
    }

    int first_above(int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (maxs[x] >= v && lx < count)
                return lx;
            else
                return -1;
        }
        int mid = (lx + rx) / 2;
        int leftmax = maxs[2 * x + 1];
        if (v <= leftmax) {
            return first_above(v, 2 * x + 1, lx, mid);
        } else {
            return first_above(v, 2 * x + 2, mid, rx);
        }
    }

    int first_above(int v) {
        return first_above(v, 0, 0, size);
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
            int x;
            cin >> x;
            cout << st.first_above(x) << endl;
        }
    }

    return 0;
}