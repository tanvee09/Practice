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

    void invert(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = (sums[x] == 1 ? 0 : 1);
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
            invert(i, 2 * x + 1, lx, mid);
        else 
            invert(i, 2 * x + 2, mid, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void invert(int i) {
        invert(i, 0, 0, size);
    }

    int indexofk(int k, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (k == 0) return lx;
            else return -1;
        }
        int mid = (lx + rx) / 2;
        if (sums[2 * x + 1] > k) {
            return indexofk(k, 2 * x + 1, lx, mid);
        } else {
            return indexofk(k - sums[2 * x + 1], 2 * x + 2, mid, rx);
        }
    }

    int indexofk(int k) {
        return indexofk(k, 0, 0, size);
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
            int i;
            cin >> i;
            st.invert(i);
        } else {
            int k;
            cin >> k;
            cout << st.indexofk(k) << endl;
        }
    }

    return 0;
}