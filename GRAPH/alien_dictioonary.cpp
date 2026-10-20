// class Solution {
// public:
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         vector<int> indegree(V);
//         queue<int> q;
//         vector<vector<int>> adj(V);
//         vector<int> ans;
//         for(auto edge:edges)
//         {
//             adj[edge[0]].push_back(edge[1]);
//         }
//         for(int i=0;i<V;i++)
//         {
//             for(int it:adj[i])
//             {
//                 indegree[it]++;
//             }
//         }
//         for(int i=0;i<V;i++)
//         {
//             if(!indegree[i])
//             {
//                 q.push(i);
//             }
//         }
//         while(!q.empty())
//         {
//             int curr=q.front();
//             q.pop();
//             ans.push_back(curr);
//             for(int it:adj[curr])
//             {
//                 indegree[it]--;
//                 if(indegree[it]==0) q.push(it);
//             }
//         }
        
//         return ans;
//     }

//     string findOrder(int n, vector<string>& words,int k) {
        
//         vector<vector<int>> adj(k);
//         for(int i=0;i<n-1;i++)
//         {
//             string s1=words[i];
//             string s2=words[i+1];
//             int len=min(s1.length(),s2.length());
//             bool found = false;
//             for(int it=0;it<len;it++)
//             {
//                 if(s1[it]!=s2[it])
//                 {
//                     adj[s1[it]-'a'].push_back(s2[it]-'a');
//                     found = true;
//                     break;
//                 }
//             }
            
//             if(!found && s1.length() > s2.length()) {
//                 return "";
//             }
//         }
        
//         vector<int> topo=topoSort(k,adj);
        
//         string ans="";
//         for(auto it:topo)
//         {
//             ans += char(it+'a');
//         }
        
//         return ans;
//     }
// };