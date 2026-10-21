To find the minimum number of swaps required to make the original array equal to the sorted array, you can use cycle detection.
Approach: Cycle detection — \(O(n\log n)\)
1. Store each element with its original index.
2. Sort these pairs by element value.
3. Each element now knows its target position.
4. Find cycles in the index mapping. A cycle of length \(k\) requires \(k-1\) swaps.
C++ code
Important: This code works for distinct elements. If duplicates exist, the pair-to-target mapping may need special handling depending on whether any sorted arrangement is acceptable.

#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>& arr) {
    int n = arr.size();

    vector<pair<int, int>> p;

    for (int i = 0; i < n; i++) {
        p.push_back({arr[i], i});
    }

    sort(p.begin(), p.end());

    vector<bool> vis(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i] || p[i].second == i)
            continue;

        int cycleSize = 0;
        int j = i;

        while (!vis[j]) {
            vis[j] = true;
            j = p[j].second;
            cycleSize++;
        }

        if (cycleSize > 1)
            swaps += cycleSize - 1;
    }

    return swaps;
}

int main() {
    vector<int> arr = {4, 3, 2, 1};

    cout << minSwaps(arr) << endl;
    return 0;
}
