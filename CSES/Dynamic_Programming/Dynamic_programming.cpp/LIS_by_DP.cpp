// int LIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n+1,0);

//         for(int i=n-1;i>=0;i--)
//         {
//             vector<int> temp(n+1,0);
//             for(int j=i-1;j>=-1;j--)
//             {
//                 int nottake=dp[j+1];
//                 int take=0;
//                 if(j==-1 || nums[i]>nums[j])
//                 {
//                     take=1+dp[i+1];
//                 }

//                 temp[j+1]=max(take,nottake);
//             }
//             dp=temp;
//         }
//          return dp[0];
//     }