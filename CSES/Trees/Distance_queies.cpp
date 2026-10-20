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
    int n,q;
    cin>>n>>q;
    vector<vector<int>> tree(n+1);
    for(int i=2;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<vector<int>> queries(q);
    for(int i=0;i<q;i++)
    {
        int u,v;
        cin>>u>>v;
        queries[i]={u,v};
    }

    vector<int> res(q);
    for(int i=0;i<q;i++)
    {
        int u=queries[i][0];
        int v=queries[i][1];
        vector<int> dist(n+1,0);
        dfs(u,-1,tree,dist);
        res[i]=dist[v];
    }

    for(int i=0;i<q;i++)
    {
        cout<<res[i]<<"\n";
    }

    return 0;
}