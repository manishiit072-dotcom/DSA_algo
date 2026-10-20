// int longestAlternating(vector<int>& nums) {   // remove at most one element 
//         int n=nums.size();
//         if(n==1) return 1;
//         vector<vector<int>> prefix(n,vector<int>(2,1));
//         for(int i=1;i<n;i++) {
//             if(nums[i]>nums[i-1]) prefix[i][0]=1+prefix[i-1][1];
//             if(nums[i]<nums[i-1]) prefix[i][1]=1+prefix[i-1][0];

//         }
//         vector<vector<int>>suffix(n,vector<int>(2,1));
//         for(int i=n-2;i>=0;i--) {
//             if(nums[i]<nums[i+1]) suffix[i][1]=1+suffix[i+1][0];
//             if(nums[i]>nums[i+1]) suffix[i][0]=1+suffix[i+1][1];
//         }
//         int ans=1;
//         for(int i=0;i<n;i++) {
//             ans=max({ans,prefix[i][0],prefix[i][1]});
//         }
//         for(int i=0;i<n;i++) {
//             //removing ith index
//             if(i>0 && i<n-1) {
//                 if(nums[i+1]<nums[i-1]) {
//                     ans=max(ans,prefix[i-1][0]+suffix[i+1][1]);
//                 }
//                 if(nums[i+1]>nums[i-1]) {
//                     ans=max(ans,prefix[i-1][1]+suffix[i+1][0]);
//                 }
//             }
//         }
//         return ans;
//     }