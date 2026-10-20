/*
  (≧◡≦)
   /|\
    |
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> segTree;

void build(long long i, long long l, long long r, vector<long long>& arr)
{
    if (l == r)
    {
        segTree[i] = arr[l];
        return;
    }

    long long mid = l + (r - l) / 2;

    build(2 * i + 1, l, mid, arr);
    build(2 * i + 2, mid + 1, r, arr);
}

void update(long long i, long long l, long long r,
            long long ll, long long rr, long long val)
{
    // Completely outside
    if (rr < l || r < ll)
    {
        return;
    }

    // Completely inside
    if (ll <= l && r <= rr)
    {
        segTree[i] += val;
        return;
    }

    long long mid = l + (r - l) / 2;

    update(2 * i + 1, l, mid, ll, rr, val);
    update(2 * i + 2, mid + 1, r, ll, rr, val);
}

long long get(long long i, long long l, long long r, long long idx)
{
    if (l == r)
    {
        return segTree[i];
    }

    long long mid = l + (r - l) / 2;

    if (idx <= mid)
    {
        return segTree[i] + get(2 * i + 1, l, mid, idx);
    }

    return segTree[i] + get(2 * i + 2, mid + 1, r, idx);
}

int main()
{
    long long n, q;
    cin >> n >> q;

    vector<long long> arr(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    segTree.assign(4 * n, 0);

    // IMPORTANT: Build the tree first
    build(0, 0, n - 1, arr);

    while (q--)
    {
        long long w;
        cin >> w;

        if (w == 1)
        {
            long long a, b, u;
            cin >> a >> b >> u;
            --a;
            --b;
            update(0, 0, n - 1, a, b, u);
        }
        else if (w == 2)
        {
            long long k;
            cin >> k;
            --k;
            cout << get(0, 0, n - 1, k) << '\n';
        }
    }

    return 0;
}