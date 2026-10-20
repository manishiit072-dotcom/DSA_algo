#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
// int main()
// {
//     vector<vector<int>> vec={{2,3,1},{0},{0,4},{0},{2}};
//     int n=vec.size();
//     vector<int> ans;
//     vector<bool> visit(n,false);
//     stack<int> s;
//     s.push(0);
//     visit[0]=true;
//     while(!s.empty())
//     {
//         int current=s.top();
//         s.pop();
//         ans.push_back(current);
//         vector<int> neighbour=vec[current];
//         reverse(neighbour.begin(),neighbour.end());
//         for(int neighbours:neighbour)
//         {
//             if(!visit[neighbours])
//             {
//                 s.push(neighbours);
//                 visit[neighbours]=true;
//             }
//         }
//     }

//     for(int val:ans)
//     {
//         cout<<val<<" ";
//     }

//     return 0;

// }





       void dfs(int node,vector<int>& ans,vector<bool>& visit,vector<vector<int>>& adj)
       {
           visit[node]=true;
           ans.push_back(node);
           for(auto it:adj[node])
           {
               if(!visit[it])
                {
                    dfs(it,ans,visit,adj);
                }
           }
       }
        // Function to return a list containing the DFS traversal of the graph.
        int main()
        {
            vector<vector<int>> vec={{2,3,1},{0},{0,4},{0},{2}};
            int n=vec.size();
            vector<int> ans;
            vector<bool> visit(n,false);
            for(int i=0;i<n;i++)
             {
                 if(!visit[i])
                 {
                     dfs(i,ans,visit,vec);
                 }
             }
            
            for(int val:ans)
            {
                cout<<val<<" ";
            }
            return 0;
        }
