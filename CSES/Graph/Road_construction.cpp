#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
      vector<int> parent,size;
      int maxi,component;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        maxi=1;
        component=n;
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int findUPar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
        {
            return;
        }
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            maxi=max(maxi,size[ulp_v]);
            component--;

        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
            maxi=max(maxi,size[ulp_u]);
            component--;
        }
    }
};
void solve()
{
    int n,m;
    cin>>n>>m;
    DisjointSet ds(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        ds.unionBySize(u,v);
        cout<<ds.component<<" "<<ds.maxi<<endl;
    }
}
int main()
{
    solve();
    return 0;
}