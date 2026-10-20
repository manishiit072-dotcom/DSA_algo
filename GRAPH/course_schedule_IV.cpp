// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         vector<vector<int>> graph(numCourses);
//         for(auto it:prerequisites)
//        {
//             int u=it[0];
//             int v=it[1];
//             graph[u].push_back(v);
//         }
//         vector<unordered_set<int>> reachable(numCourses);
//         for(int i=0;i<numCourses;i++)
//         {
//             queue<int> q;
//             q.push(i);
//             reachable[i].insert(i);
//             while(!q.empty())
//             {
//                 int node=q.front();
//                 q.pop();
//                 for(int it:graph[node])
//                 {
//                     if(reachable[i].find(it)==reachable[i].end())
//                     {
//                         reachable[i].insert(it);
//                         q.push(it);
//                     }
//                 }
//             }
//         }
        
//         vector<bool> check(queries.size());
//         for(int i=0;i<queries.size();i++)
//         {
//             int u=queries[i][0];
//             int v=queries[i][1];
           
//             check[i]=(reachable[u].find(v)!=reachable[i].end());
//         }

//         return check;
//     }
// };












// class Solution {
// public:
//     bool bfs(int u,int v,vector<vector<int>>& graph)
//     {
//         if(u==v) return true;
//         queue<int> q;
//         unordered_set<int> visit;
//         q.push(u);
//         visit.insert(u);
//         while(!q.empty())
//         {
//             int node=q.front();
//             q.pop();
//             if(node==v)
//             {
//                 return true;
//             }
//             for(int neighbour:graph[node])
//             {
//                 if(visit.find(neighbour)==visit.end())
//                 {
//                     visit.insert(neighbour);
//                     q.push(neighbour);
//                 }
//             }
//         }

//         return false;
//     }
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         vector<vector<int>> graph(numCourses);
//         for(const auto& it:prerequisites)
//         {
//              int u=it[0];
//              int v=it[1];
//              graph[u].push_back(v);
//         }

        
//         vector<bool> check;
//         for(const auto& it:queries)
//         {
//             int u=it[0];
//             int v=it[1];
//             check.push_back(bfs(u,v,graph));
//         }


//         return check;
//     }
// };







// class Solution {
// public:
//     bool dfs(int u,int v,vector<vector<int>>& graph,vector<bool>& visit)
//     {
//         if(u==v) return true;
//         visit[u]=true;
//         for(int neighbour:graph[u])
//         {
//             if(!visit[neighbour] && dfs(neighbour,v,graph,visit))
//             {
//                 return true;
//             }
//         }

//         return false;
//     }
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         vector<vector<int>> graph(numCourses);
//         for(const auto& it:prerequisites)
//         {
//              int u=it[0];
//              int v=it[1];
//              graph[u].push_back(v);
//         }

        
//         vector<bool> check;
//         for(const auto& it:queries)
//         {
//             int u=it[0];
//             int v=it[1];
//             vector<bool> visit(numCourses,false);
//             check.push_back(dfs(u,v,graph,visit));
//         }


//         return check;
//     }
// };
