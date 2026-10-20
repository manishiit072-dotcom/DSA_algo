// class Solution {
//     public:
//         void postord(TreeNode* root,stack<int>& st)
//         {
//             if(root)
//             {
//                 postord(root->left,st);
//                 postord(root->right,st);
//                 st.push(root->val);
                
//             }
//         }
//         vector<int> postorderTraversal(TreeNode* root) {
//             stack<int> st;
//             vector<int> ans;
//             postord(root,st);
//             while(!st.empty())
//             {
//                 ans.push_back(st.top());
//                 st.pop();
//             }
//             reverse(ans.begin(),ans.end());
            
    
//             return ans;
//         }
//     };