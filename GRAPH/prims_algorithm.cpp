#include<bits/stdc++.h>
using namespace std; 
// for unidirected graph
// TC->((V+E)logV) 
// SC->O(V)+O(V)+O(E) ~ O(V+E) // O(V) for visit array and O(V) for priority queue and O(E) for adjacency list
class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
       vector<int> visit(V,0);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       pq.push({0,0});//{wt,node}
       int sum=0;
       while(!pq.empty())
       {
        auto it=pq.top();
        int wt=it.first;
        int node=it.second;
        pq.pop();
        if(visit[node]==1) continue;

        visit[node]=1;
        sum+=wt;
        for(auto it:adj[node])
        {
            int adjnode=it[0];
            int edgewt=it[1];
            if(!visit[adjnode])
            {
                pq.push({edgewt,adjnode});
            }
        }
       }

       return sum;
    }
};



// class Solution {
//   public:
//     int spanningTree(int V, vector<vector<int>>& edges) {
//        vector<vector<pair<int,int>>> adj(V);
//        for(int i=0;i<edges.size();i++)
//        {
//            int wt=edges[i][2];
//            int u=edges[i][0];
//            int v=edges[i][1];
           
//            adj[u].push_back({wt,v});
//            adj[v].push_back({wt,u});
//        }
       
//        vector<bool> visit(V,false);
//        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//        pq.push({0,0}); // {wt,node}
//        int sum=0;
//        while(!pq.empty())
//        {
//            int wt=pq.top().first;
//            int node=pq.top().second;
//            pq.pop();
//            if(visit[node]) continue;
//            visit[node]=true;
//            sum+=wt;
//            for(auto it:adj[node])
//            {
//                int adjwt=it.first;
//                int adjnode=it.second;
//                if(!visit[adjnode])
//                {
//                    pq.push({adjwt,adjnode});
//                }
//            }
//        }
       
//        return sum;
//     }
// };
