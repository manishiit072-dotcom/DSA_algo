// BIT has 1-based indexing. For 0-based indexing, use idx+1 in update and query functions.

#include<bits/stdc++.h>
using namespace std;
class BIT {
    int n;
    vector<long long> bit;

public:
    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // Add val at index idx (zero-based).
    void update(int idx, long long val) {
        idx++;  // Convert to 1-based indexing

        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    // Prefix sum from index 0 to idx.
    long long prefixQuery(int idx) {
        idx++;  // Convert to 1-based indexing
        long long sum = 0;

        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }

        return sum;
    }

    // Range sum from l to r (inclusive).
    long long rangeQuery(int l, int r) {
        if (l > r) return 0;

        return prefixQuery(r) - prefixQuery(l - 1);
    }
};
