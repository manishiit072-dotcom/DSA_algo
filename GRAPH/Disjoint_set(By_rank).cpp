#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> size,parent;
    vector<int> rank;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }

        int findUPar(int node) // find ultimate parent 
        {
            if(node==parent[node])
            {
            return node;
            }
            return parent[node]=findUPar(parent[node]);
        }

        void unionByRank(int u,int v)
        {
            int pu=findUPar(u);  // find ultimate parent of u
            int pv=findUPar(v);  // find ultimate parent of v
            if(pu==pv) return;
            if(rank[pu]<rank[pv])
            {
                parent[pu]=pv;
            }
            else if(rank[pv]<rank[pu])
            {
                parent[pv]=pu;
                
            }
            else{
                parent[pv]=pu;
                rank[pu]++;
            }
        }

        void unionBySize(int u,int v)
        {
            int pu=findUPar(u);
            int pv=findUPar(v);
            if(pu==pv) return;
            if(size[pu]<size[pv])
            {
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
            else{
                 parent[pv]=pu;
                size[pu]+=size[pv];
            }
        }

      };


int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "3 and 7 are in the same set." << endl;
    }
    else
    {
        cout << "3 and 7 are in different sets." << endl;
    }
    ds.unionByRank(3,7);
}



