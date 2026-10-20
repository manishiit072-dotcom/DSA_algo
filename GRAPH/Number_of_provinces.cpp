// class Solution {
//     public:
//         void dfs(int node,vector<vector<int>>& arr,vector<bool>& visit)
//         {
//             visit[node]=true;
//             for(auto it:arr[node])
//             {
//                 if(!visit[it])
//                 {
//                     dfs(it,arr,visit);
//                 }
//             }
    
//         }
//         int findCircleNum(vector<vector<int>>& arr) {
//             int n=arr.size();
//             int cnt=0;
//             vector<vector<int>> ans(n);
//             for(int i=0;i<n;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 {
//                     if(arr[i][j]==1 && i!=j){
//                     ans[i].push_back(j);
//                     ans[j].push_back(i);
//                     }
//                 }
//             }
        
//             vector<bool> visit(n,false);
//             for(int i=0;i<n;i++)
//             {
//                 if(!visit[i])
//                 {
//                     cnt++;
//                     dfs(i,ans,visit);
//                 }
//             }
    
//             return cnt;
    
//         }
//     };