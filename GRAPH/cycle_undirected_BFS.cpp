class Solution {
public:
    bool detect(int root, vector<vector<int>>& vec, vector<int>& visit) {
        visit[root] = 1;
        queue<pair<int, int>> q;
        q.push({root, -1});
        while (!q.empty()) {
            auto it = q.front();
            int node = it.first;
            int parent = it.second;
            q.pop();
            for (auto adjnodes : vec[node]) {
                if (!visit[adjnodes]) {
                    visit[adjnodes] = 1;
                    q.push({adjnodes, node});
                }
                else if (parent != adjnodes) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> visit(V, 0);
        vector<vector<int>> adj(V);  
        
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < V; i++) {
            if (!visit[i]) {
                if (detect(i, adj, visit)) return true;
            }
        }
        return false;
    }
};


// TC->O(V+2*E)
// SC->O(V)+O(V)