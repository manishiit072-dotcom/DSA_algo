// class Solution {
// public:
//     vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
//         // if (V == 0) return {}; // No nodes, return empty
//         // if (src < 0 || src >= V) return {}; // Fix: Check src >= V instead of src > V

//         vector<int> distance(V, 1e8);
//         distance[src] = 0;

//         // Relax edges V-1 times
//         for (int i = 0; i < V - 1; i++) {
//             for (auto& it : edges) {
//                 int u = it[0];
//                 int v = it[1];
//                 int edgewt = it[2];
//                 if (distance[u] != 1e8 && distance[u] + edgewt < distance[v]) {
//                     distance[v] = distance[u] + edgewt;
//                 }
//             }
//         }

//         // Check for negative cycles
//         for (auto& it : edges) {
//             int u = it[0];
//             int v = it[1];
//             int edgewt = it[2];
//             if (distance[u] != 1e8 && distance[u] + edgewt < distance[v]) {
//                 return {-1}; // Negative cycle detected
//             }
//         }

//         return distance;
//     }
};