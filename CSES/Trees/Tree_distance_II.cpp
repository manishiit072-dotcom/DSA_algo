#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,vector<vector<int>>& tree,vector<int>& dist)
{
    for(auto it:tree[node])
    {
        if(it==parent) continue;
        dist[it]=1+dist[node];
        dfs(it,node,tree,dist);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    vector<int> sum(n+1,0);
    for(int i=2;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        vector<int> distances(n+1,0);
        dfs(i,-1,tree,distances);

        sum[i]=accumulate(distances.begin(),distances.end(),0);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<sum[i]<<" ";
    }

    return 0;
}