// maximum sum segment

#include<bits/stdc++.h>
using namespace std;


struct node {
    long long pref, suff, seg, sum;
    node(long long _pref, long long _suff, long long _seg, long long _sum) {
        pref = _pref;
        suff = _suff;
        seg = _seg;
        sum = _sum;
    }
};

// long long max(long long a, long long b) {
//     if (a > b) return a; else return b;
// }

// long long max(long long a, long long b, long long c) {
//     return max(a, max(b, c));
// }

// long long max(long long a, long long b, long long c, long long d) {
//     return max(a, max(b, max(c, d)));
// }


class SegTree {
private:
    int size;
    vector<node> segs;

    node NEUTRAL_ELEMENT = {0, 0, 0, 0};
public:
    SegTree(int n) {
        size = 1;
        while (size < n) { size *= 2; }
        segs.assign(2 * size, NEUTRAL_ELEMENT);
    }

    node combine(node left, node right) {
        long long _pref = max(left.pref, left.sum + right.pref);
        long long _suff = max(right.suff, right.sum + left.suff);
        long long _seg = max(left.seg, max(right.seg, left.suff + right.pref));
        long long _sum = left.sum + right.sum;
        return node(_pref, _suff, _seg, _sum);
    }

    node single(int v) {
        if (v > 0) {
            return node(v, v, v, v);
        } else {
            return node(0, 0, 0, v);
        }
    }

    void build(vector<long long> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size())
                segs[x] = single(arr[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        segs[x] = combine(segs[2 * x + 1], segs[2 * x + 2]);
    }

    void build(vector<long long> &arr) {
        build(arr, 0, 0, size);
    }

    void set(int i, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            segs[x] = single(v);
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else 
            set(i, v, 2 * x + 2, mid, rx);
        segs[x] = combine(segs[2 * x + 1], segs[2 * x + 2]);
    }

    void set(int i, long long v) {
        set(i, v, 0, 0, size);
    }

    node calc(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r) return segs[x];
        int mid = (lx + rx) / 2;
        node s1 = calc(l, r, 2 * x + 1, lx, mid);
        node s2 = calc(l, r, 2 * x + 2, lx, mid);
        return combine(s1, s2);
    }

    node calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};

int main()
{
    long long n, m;
    cin >> n >> m;
    SegTree st(n);

    vector<long long> arr(n);
    for (long long i = (long long)0; i < n; i++) cin >> arr[i];
    st.build(arr);

    cout << st.calc(0, n).seg<< endl;

    while(m--) {
        long long i, v;
        cin >> i >> v;
        st.set(i, v);
    
        cout << st.calc(0, n).seg << endl;
    }

    return (long long)0;
}