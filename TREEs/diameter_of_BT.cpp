// class Solution {
// public:
//     int diameter=0;

//     int height(TreeNode* root)
//     {
//         if(!root) return 0;
         
//         int lh=height(root->left);
//         int rh=height(root->right);
//         diameter=max(diameter,lh+rh);




//         return max(lh,rh)+1;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root) return 0;
         
//         height(root);

//         return diameter;

//     }
// };