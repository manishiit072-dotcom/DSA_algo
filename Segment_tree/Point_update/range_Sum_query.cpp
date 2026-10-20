
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> seg;

public:
    // Constructor
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    // Build the segment tree
    void build(int idx, int low, int high,
               vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;

        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        seg[idx] = seg[2 * idx + 1]
                 + seg[2 * idx + 2];
    }

    // Point update: set arr[pos] = val
    void update(int idx, int low, int high,
                int pos, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;

        if (pos <= mid) {
            update(2 * idx + 1, low, mid, pos, val);
        } else {
            update(2 * idx + 2, mid + 1, high,
                   pos, val);
        }

        // Recalculate ancestors
        seg[idx] = seg[2 * idx + 1]
                 + seg[2 * idx + 2];
    }

    // Public point update
    void pointUpdate(int pos, int val) {
        if (pos < 0 || pos >= n) return;

        update(0, 0, n - 1, pos, val);
    }

    // Range sum query [l, r]
    int query(int idx, int low, int high,
              int l, int r) {
        // No overlap
        if (high < l || low > r)
            return 0;

        // Complete overlap
        if (l <= low && high <= r)
            return seg[idx];

        // Partial overlap
        int mid = low + (high - low) / 2;

        int left = query(2 * idx + 1, low, mid,
                         l, r);

        int right = query(2 * idx + 2, mid + 1, high,
                          l, r);

        return left + right;
    }

    // Public range query
    int rangeQuery(int l, int r) {
        if (l < 0 || r >= n || l > r)
            return 0;

        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    SegmentTree st(arr);

    // Initial range sum
    cout << st.rangeQuery(1, 3) << '\n';
    // Output: 15 (3 + 5 + 7)

    // Update index 2 to 10
    st.pointUpdate(2, 10);

    // Query after update
    cout << st.rangeQuery(1, 3) << '\n';
    // Output: 20 (3 + 10 + 7)

    // Update index 0 to 100
    st.pointUpdate(0, 100);

    cout << st.rangeQuery(0, 2) << '\n';
    // Output: 113 (100 + 3 + 10)

    return 0;
}
