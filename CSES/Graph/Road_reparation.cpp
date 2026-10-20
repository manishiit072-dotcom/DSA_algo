#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
      vector<long long> parent,size;
      long long maxi,component;
    DisjointSet(long long n)
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

    long long findUPar(long long node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(long long u,long long v)
    {
        long long ulp_u=findUPar(u);
        long long ulp_v=findUPar(v);
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
    long long n,m;
    cin>>n>>m;
    vector<pair<long long,pair<long long,long long>>> edges;
     long long cost=0;
    long long minicost=0;
    for(long long i=0;i<m;i++)
    {
        long long u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
        cost+=wt;
    }
        sort(edges.begin(),edges.end());

        DisjointSet ds(n);
       
        for(auto it:edges)
        {
            long long wt=it.first;
            long long u=it.second.first;
            long long v=it.second.second;
            
            if(ds.findUPar(u)!=ds.findUPar(v))
            {
                ds.unionBySize(u,v);
                minicost+=wt;
            }
        }

        
    

    if(ds.component>1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        cout<<minicost<<endl;
    }


}
int main()
{
    solve();
    return 0;
}