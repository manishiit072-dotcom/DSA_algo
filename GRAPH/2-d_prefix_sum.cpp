// class Solution {
// public:
//     int countSubmatrices(vector<vector<int>>& grid, int k) {
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int>> prefix(n,vector<int>(m,0));
//         prefix[0][0]=grid[0][0];

//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 prefix[i][j]=grid[i][j]+((i-1>=0)?prefix[i-1][j]:0)+((j-1>=0)?prefix[i][j-1]:0)-((i-1>=0 && j-1>=0)?prefix[i-1][j-1]:0);
//             }
//         }

//         int cnt=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(prefix[i][j]<=k)
//                 {
//                     cnt++;
//                 }
//             }
//         }
        



//         return cnt;
//     }
// };