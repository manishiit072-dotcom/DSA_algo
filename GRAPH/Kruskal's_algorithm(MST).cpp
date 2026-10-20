#include<bits/stdc++.h> 
using namespace std;  // used to find the (MST) with DSU
// for unidirected graph
// TC->O(ElogE) + O(E*4*alpha) ~ O(ElogE)  // O(ElogE) for sorting the edges and O(E*4*alpha) for union and find operations or O(ElogV) for union and find operations where alpha is the inverse Ackermann function which is very slow growing function and for all practical purposes we can consider it as constant
// SC->O(V)+O(V)+O(E) ~ O(V+E) // O(V) for parent and size arrays and O(E) for edges array
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

// step1-> sort all the edges according to their weights
// step2-> start picking the edges from the sorted array and check if the nodes of that edge belong to the same component or not if they belong to different component then we will take that edge in our MST and perform union operation on those two nodes otherwise we will discard that edge
// step3-> we will keep on doing this until we have n-1 edges in our MST where n->is the number of nodes in the graph 
int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<pair<int,pair<int,int>>> edge;
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            edge.push_back({wt,{u,v}});
        }
        sort(edge.begin(),edge.end());
        int MstWt=0;
        DisjointSet ds(V);
        for(auto it:edge)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findUPar(u)!=ds.findUPar(v))
            {
                MstWt+=wt;
                ds.unionByRank(u,v);
            }
        }
        
        return MstWt;
        
    }

