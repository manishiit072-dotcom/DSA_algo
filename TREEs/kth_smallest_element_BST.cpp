// class Solution {
//     public:
//        void inorderTraversal(TreeNode* root,vector<int>& ans)
//        {
//         if(root)
//         {
//             inorderTraversal(root->left,ans);
//             ans.push_back(root->val);
//             inorderTraversal(root->right,ans);
//         }
//        }
//         int kthSmallest(TreeNode* root, int k) {
//             vector<int> ans;
//             inorderTraversal(root,ans);
//             return ans[k-1];
//         }
//     };





// class Solution {
//     public:
//       // Return the Kth smallest element in the given BST
//       int find(Node* root,int& cnt,int k)
//       {
//           if(!root)
//           {
//               return -1;
//           }
          
//           int left=find(root->left,cnt,k);
//           if(left!=-1) return left;
          
//           cnt++;
//           if(cnt==k) return root->data;
          
//           int right=find(root->right,cnt,k);
//           return right;
//       }
//       int kthSmallest(Node *root, int k) {
//           int cnt=0;
//           return find(root,cnt,k);
//       }
//   };