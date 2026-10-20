// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(!root)
//         {
//             return ans;
//         }
//         queue<TreeNode*> q;
//         q.push(root);
        
//         bool check=true;
//         while(!q.empty())
//         {
//             int cap=q.size();
//             vector<int> currlevel(cap);
//             int index;
//             for(int i=0;i<cap;i++)
//             {
//                  TreeNode* curr=q.front();
                 
//                  q.pop();
//                  if(check)
//                  {
//                      index=i;
//                  }
//                  if(!check)
//                  {
//                      index=cap-i-1;
//                  }

                 
//                  currlevel[index]=curr->val;
//                  if(curr->left)
//                  {
//                     q.push(curr->left);
//                  }
//                  if(curr->right)
//                  {
//                     q.push(curr->right);
//                  }
//             }
//             ans.push_back(currlevel);
//             check=!check;
//         }

//         return ans;
//     }
// };