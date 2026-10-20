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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> tree(n+1);
    for(int i=2;i<=n;i++)
    {
        int boss;
        cin>>boss;
        tree[i].push_back(boss);
    }
    vector<vector<int>> query(m);
    for(int i=0;i<m;i++)
    {
        int boss,level;
        cin>>boss>>level;
        query[i]={boss,level};
    }

    vector<int> res(m);
    for(int i=0;i<m;i++)
    {
        int boss=query[i][0];
        int level=query[i][1];
        vector<int> dist(n+1,0);
        dfs(boss,-1,tree,dist);
        auto idx=find(dist.begin(),dist.end(),level);
        res[i]=(idx==dist.end())?-1:idx-dist.begin();

    }

    for(int i=0;i<m;i++)
    {
        cout<<res[i]<<" ";
    }



    return 0;

}