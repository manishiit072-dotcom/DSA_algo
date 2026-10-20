// User Function Template
class Solution {
  public:
    // vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    //     vector<vector<pair<int,int>>> adj(V);
    //     for(int i=0;i<edges.size();i++)
    //     {
    //         adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    //         adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    //     }
    //     set<pair<int,int>> st;
    //     vector<int> distance(V,1e9);
    //     st.insert({0,src});
    //     distance[src]=0;
    //     while(!st.empty())
    //     {
    //         auto it=*(st.begin());
    //         int node=it.second;
    //         int dist=it.first;
    //         st.erase(it);
    //         for(auto it:adj[node])
    //         {
    //             int adjnode=it.first;
    //             int edgewt=it.second;
    //             if(dist+edgewt<distance[adjnode])
    //             {
    //                 if(distance[adjnode]!=1e9)
    //                 {
    //                     st.erase({distance[adjnode],adjnode});
    //                 }
    //                 distance[adjnode]=dist+edgewt;
    //                 st.insert({distance[adjnode],adjnode});
    //             }
    //         }
    //     }
        
    //     return distance;
        
    // }
    
    
    
    // vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    //     vector<vector<pair<int,int>>> adj(V);
    //     for(int i=0;i<edges.size();i++)
    //     {
    //         adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    //         adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    //     }
        
    //     vector<int> distance(V,1e9);
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //     distance[src]=0;
    //     pq.push({0,src});
    //     while(!pq.empty())
    //     {
    //         auto it=pq.top();
    //         int dist=it.first;
    //         int node=it.second;
    //         pq.pop();
    //         for(auto itt:adj[node])
    //         {
    //             int edgewt=itt.second;
    //             int adjnode=itt.first;
    //             if(dist+edgewt<distance[adjnode])
    //             {
    //                 distance[adjnode]=dist+edgewt;
    //                 pq.push({distance[adjnode],adjnode});
    //             }
    //         }
    //     }
        
    //     return distance;
        
    // }
    
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int> distance(V,1e9);
        queue<pair<int,int>> pq;
        distance[src]=0;
        pq.push({0,src});
        while(!pq.empty())
        {
            auto it=pq.front();
            int dist=it.first;
            int node=it.second;
            pq.pop();
            for(auto itt:adj[node])
            {
                int edgewt=itt.second;
                int adjnode=itt.first;
                if(dist+edgewt<distance[adjnode])
                {
                    distance[adjnode]=dist+edgewt;
                    pq.push({distance[adjnode],adjnode});
                }
            }
        }
        
        return distance;
        
    }
    
};