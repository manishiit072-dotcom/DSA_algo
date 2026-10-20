#include<bits/stdc++.h>
using namespace std;
class BIT {
    int n;
    vector<long long> bit1, bit2;

    void update(vector<long long>& bit, int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    long long queryBIT(vector<long long>& bit, int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    // Prefix sum of original array [0 ... idx]
    long long prefixSum(int idx) {
        if (idx < 0) return 0;

        int p = idx + 1;

        return 1LL * p * queryBIT(bit1, p)
                    - queryBIT(bit2, p);
    }

public:
    BIT(int n) : n(n), bit1(n + 1, 0), bit2(n + 1, 0) {}

    // Add val to every index in [l, r], zero-based.
    void rangeUpdate(int l, int r, long long val) {
        if (l > r) return;

        int L = l + 1;
        int R = r + 1;

        update(bit1, L, val);
        update(bit1, R + 1, -val);

        update(bit2, L, val * (L - 1));
        update(bit2, R + 1, -val * R);
    }

    // Sum of values in [l, r], zero-based.
    long long rangeQuery(int l, int r) {
        if (l > r) return 0;

        return prefixSum(r) - prefixSum(l - 1);
    }
};
