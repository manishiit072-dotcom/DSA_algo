// class Solution {
//     public:
//         TreeNode* preToBST(vector<int>& preorder,int& i,int bound)
//         {
//             if(i==preorder.size() || preorder[i]>bound) return NULL;
//             TreeNode* root=new TreeNode(preorder[i]);
//             i++;
//             root->left=preToBST(preorder,i,root->val);
//             root->right=preToBST(preorder,i,bound);
//             return root;
//         }
//         TreeNode* bstFromPreorder(vector<int>& preorder) {
//            int i=0;
//            return preToBST(preorder,i,INT_MAX);
//         }
//     };