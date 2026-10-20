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
int main(){
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=2;i<=n;i++)
     {
        int u,v;
        cin>>u>>v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
     }
     vector<int> dist1(n+1,0);
     dfs(1,-1,tree,dist1);
     int farthest_node1=max_element(dist1.begin()+1,dist1.end())-dist1.begin();
     fill(dist1.begin(),dist1.end(),0);
     dfs(farthest_node1,-1,tree,dist1);
     int idx=max_element(dist1.begin()+1,dist1.end())-dist1.begin();
     
     cout<<dist1[idx]<<endl;
     return 0;
}