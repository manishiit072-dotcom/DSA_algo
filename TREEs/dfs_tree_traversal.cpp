// void dfs(TreeNode* root,vector<int>& path,vector<vector<int>>& ans)
// {
//     if(!root) return;
//     part.push_back(root->val);
//     if(!root->left && !root->right)
//     {
//         ans.push_back(path);
//     }
//     dfs(root->left,path,ans);
//     dfs(root->right,path,ans);
//     path.pop_back();
// }

// vector<vector<int>> tree(TreeNode* root)
// {
//     vector<vector<int>> ans;
//     if (!root) return ans;
//     vector<int> path;
//     dfs(root,path,ans);

//     return ans;

// }