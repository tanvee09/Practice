#include<bits/stdc++.h>
using namespace std;

class SegTree {
private:
    int leftmost, rightmost;
    SegTree *lchild, *rchild;
    int sum;
public:
    SegTree(int _leftmost, int _rightmost, int arr[]) {
        leftmost = _leftmost;
        rightmost = _rightmost;
        if (leftmost == rightmost) {
            sum = arr[leftmost];
            lchild = rchild = nullptr;
        } else {
            int mid = (leftmost + rightmost) / 2;
            lchild = new SegTree(leftmost, mid, arr);
            rchild = new SegTree(mid + 1, rightmost, arr);
            recalc();
        }
    }

    void recalc() {
        if (leftmost == rightmost) return;
        sum = lchild->sum + rchild->sum;
    }

    void pointUpdate(int index, int val) {
        if (index < leftmost || index > rightmost) return;
        if (leftmost == rightmost) {
            sum = val;
            return;
        }
        if (index <= lchild->rightmost) lchild->pointUpdate(index, val);
        else rchild->pointUpdate(index, val);
        recalc();
    }

    int rangeSum(int l, int r) {
        if (r < leftmost || l > rightmost) return 0;

        if (l <= leftmost && r >= rightmost) return sum;

        return lchild->rangeSum(l, r) + rchild->rangeSum(l, r);
    }
};

int main()
{
    int n = 6;
    int arr[] = {1, 2, 3, 4, 5, 6};
    SegTree st(0, n-1, arr);
    cout << st.rangeSum(1, n-2) << endl;
    st.pointUpdate(3, 3);
    cout << st.rangeSum(1, n-2) << endl;
    return 0;
}