// bool dfs(int start, vector<vector<int>>& vec, vector<bool>& visit, int parent) {
//     visit[start] = true;
    
//     for(int it : vec[start]) {
//         if(!visit[it]) {
//             if(dfs(it, vec, visit, start)) {
//                 return true;
//             }
//         }
//         else if(it != parent) {
//             return true;
//         }
//     }
//     return false;
// }

// bool isCycle(int V, vector<vector<int>>& edges) {
//     vector<bool> visit(V, false);
//     vector<vector<int>> adj(V);  
    
//     for (auto edge : edges) {
//         adj[edge[0]].push_back(edge[1]);
//         adj[edge[1]].push_back(edge[0]);
//     }

//     // Check all components
//     for(int i = 0; i < V; i++) {
//         if(!visit[i]) {
//             if(dfs(i, adj, visit, -1)) {
//                 return true;
//             }
//         }
//     }
//     return false;