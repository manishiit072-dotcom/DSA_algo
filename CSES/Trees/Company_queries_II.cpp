#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<ll>> adj;
vector<vector<ll>> ancestorTable;
vector<ll> depth;
ll cols;
void dfs(ll node,ll parent,ll d)
{
    depth[node]=d;
    ancestorTable[node][0]=parent;

    for(auto child:adj[node])
    {
        if(child==parent) continue;
        dfs(child,node,d+1);
    }
}
ll getLCA(ll u,ll v)
{
    if(depth[u]<depth[v]) swap(u,v);
    ll diff=depth[u]-depth[v];

    for(ll j=0;j<cols;j++)
    {
        if(diff&(1<<j))
        {
            u=ancestorTable[u][j];
        }
    }

    if(u==v) return u;

    for(ll j=cols-1;j>=0;j--)
    {
        if(ancestorTable[u][j]==-1 || ancestorTable[u][j]==ancestorTable[v][j]) continue;
        u=ancestorTable[u][j];
        v=ancestorTable[v][j];
    }

    return ancestorTable[u][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    cols=log2(n)+1;
    ancestorTable.assign(n+1,vector<ll>(cols,-1));
    depth.assign(n+1,0);
    adj.resize(n+1,{});
    for(ll i=2;i<=n;i++)
    {
        ll parent;
        cin>>parent;
        adj[parent].push_back(i);
        adj[i].push_back(parent);
    }
    
     dfs(1,-1,0);
    for(ll j=1;j<cols;j++)
    {
        for(ll node=1;node<=n;node++)
        {
            if(ancestorTable[node][j-1]!=-1)
            {
                ancestorTable[node][j]=ancestorTable[ancestorTable[node][j-1]][j-1];
            }
        }
    }

    for(ll i=0;i<q;i++)
    {
        ll u,v;
        cin>>u>>v;
        cout<<getLCA(u,v)<<"\n";
    }

    return 0;

}
