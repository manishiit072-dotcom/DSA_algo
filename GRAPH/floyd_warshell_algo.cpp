// class Solution {
//   public:
//     void floydWarshall(vector<vector<int>> &dist) {
//         int n=dist.size();
        
        
//         for(int k=0;k<n;k++)
//         {
//             for(int i=0;i<n;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 {
//                     if(dist[i][k]!=100000000 && dist[k][j]!=100000000)
//                     {
//                         dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
//                     }
//                 }
//             }
//         }
        
//     }
// };



// TC->O(N^3)
// SC->O(1)

// variation of the floyd warshall algo to find shortest distance between all pairs of nodes in a weighted graph

// class Solution {
// public:
//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         int  n=original.size();
//         vector<vector<long long>> c(26,vector<long long>(26,LLONG_MAX));
//         for(int i=0;i<26;i++)
//         {
//             c[i][i]=0;
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(original[i]==changed[i])
//             {
//                 c[original[i]-'a'][changed[i]-'a']=0;
//             }
//            else
//             {
//                 c[original[i]-'a'][changed[i]-'a']=min(c[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
//             }
//         }



        
//         for(int k=0;k<26;k++)
//         {
//             for(int i=0;i<26;i++)
//             {
//                 for(int j=0;j<26;j++)
//                 {
//                     if(c[i][k]!=LLONG_MAX && c[k][j]!=LLONG_MAX){
//                     c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
//                     }
//                 }
//             }
//         }

//         int len=source.length();
//         long long sum=0;
//         int cnt=0;
//         for(int i=0;i<len;i++)
//         {
//             int x=source[i]-'a';
//             int y=target[i]-'a';
//             if(c[x][y]==LLONG_MAX)
//             {
//                 cnt++;
//             }
//             else{
//             sum+=c[x][y];
//             }

//         }

//         return cnt==0?sum:-1;


        


        
//     }
// };