#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> tin,tout,eulerTour;
int timer;
vector<int> depth;
void EulerTour(int n)
{
    timer=0;
    adj.resize(n,{});
    tin.assign(n,0);
    tout.assign(n,0);
    eulerTour.assign(2*n,0);
    depth.resize(n,0);
}
void dfs(int node,int parent,int d)
{
    depth[node]=d;
    tin[node]=timer;
    eulerTour[timer]=node;
    timer++;

    for(auto child:adj[node])
    {
        if(child==parent) continue;
        dfs(child,node,d+1);
    }

    tout[node]=timer;
    eulerTour[timer]=node;
    timer++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> edges;
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    for(int i=0;i<n;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    EulerTour(n);
    dfs(0,-1,0);
    return 0;
}
