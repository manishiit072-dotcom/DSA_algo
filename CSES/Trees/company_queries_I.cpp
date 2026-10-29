
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<ll>> adj;
vector<vector<ll>> ancestorTable;
vector<ll> depth;
ll cols;

void dfs(ll node, ll parent, vector<vector<ll>>& adj)
{
    ancestorTable[node][0] = parent;


    for (ll child : adj[node])
    {
        if (child == parent)
            continue;

        depth[child] = depth[node] + 1;
        dfs(child, node, adj);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    cols = log2(n) + 1;

    depth.resize(n + 1, 0);
    ancestorTable.resize(n + 1, vector<ll>(cols, -1));
    adj.resize(n + 1);

    for (ll i = 2; i <= n; i++)
    {
        ll parent;
        cin >> parent;

        adj[parent].push_back(i);
        adj[i].push_back(parent);
    }
    

    dfs(1, -1, adj);
    for(int j = 1; j < cols; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            if (ancestorTable[i][j - 1] != -1)
            {
                ancestorTable[i][j] = ancestorTable[ancestorTable[i][j - 1]][j - 1];
            }
        }
    }

    for (ll i = 1; i <= q; i++)
    {
        ll node, k;
        cin >> node >> k;

        bool flag = true;

        for (ll j = 0; j < cols; j++)
        {
            if (k & (1LL << j))
            {
                node = ancestorTable[node][j];

                if (node == -1)
                {
                    cout << -1 << '\n';
                    flag = false;
                    break;
                }
            }
        }

        if (!flag)
            continue;

        cout << node << '\n';
    }

    return 0;
}
