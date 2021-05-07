// Xenia and Bit Operations https://codeforces.com/contest/339/problem/D

#include<bits/stdc++.h>
using namespace std;


struct node {
    int xor_, or_, level;
    node(int _xor, int _or, int _level) {
        xor_ = _xor;
        or_ = _or;
        level = _level;
    }
};

class SegTree {
private:
    int size;
    vector<node> segs;
    node NEUTRAL_ELEMENT = {0, 0, 0};
    int levels;
public:
    SegTree(int n) {
        size = 1;
        while (size < n) { size *= 2; }
        segs.assign(2 * size, NEUTRAL_ELEMENT);
    }

    int length() {
        return size;
    }

    node combine(node left, node right) {
        int _xor = left.or_ ^ right.or_;
        int _or = left.xor_ | right.xor_;
        int _lvl = left.level + 1;
        return node(_xor, _or, _lvl);
    }

    node single(int v) {
        return node(v, v, 0);
    }

    int build(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size())
                segs[x] = single(arr[lx]);
            return 0;
        }
        int mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        segs[x] = combine(segs[2 * x + 1], segs[2 * x + 2]);
        levels = max(levels, segs[x].level);
        return segs[x].level;
    }

    void build(vector<int> &arr) {
        levels = build(arr, 0, 0, size);
        // for (int i = 0; i < 2 * size; i++) {
        //     cout << segs[i].xor_ << "," << segs[i].or_ << "," << segs[i].level << "\t";
        // }
        // cout << endl;
    }

    void set(int i, int v, int x, int lx, int rx) {
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

    void set(int i, int v) {
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

    int ans() {
        if (levels % 2 == 0) return segs[0].xor_;
        else return segs[0].or_;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    SegTree st(pow(2, n));

    int size = st.length();
    vector<int> arr(size);
    for (int i = (int)0; i < size; i++) cin >> arr[i];
    st.build(arr);


    while(m--) {
        int i, v;
        cin >> i >> v;
        st.set(i - 1, v);
    
        cout << st.ans() << endl;
    }

    return (int)0;
}