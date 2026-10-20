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
//             stack<int> st1;
//             stack<int> st2;
//             vector<int> ans;
//             postord(root,st1);
//             while(!st1.empty())
//             {
//                 st2.push(st1.top());
//                 st1.pop();
//             }
//             while(!st2.empty())
//             {
//                 ans.push_back(st2.top());
//                 st2.pop();
//             }
            
    
//             return ans;
//         }
//     };