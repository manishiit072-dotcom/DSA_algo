
// class Solution {
//     public:
//         TreeNode* prev=NULL;
//         void preTraversal(TreeNode* root)
//         {
//             if(!root) return;
//             preTraversal(root->right);
//             preTraversal(root->left);
//             root->right=prev;
//             root->left=NULL;
//             prev=root;
//         }
//         void flatten(TreeNode* root) {
//             if(!root) return;
//             preTraversal(root);
//         }
//     };





// void flatten(TreeNode* root) {
//         if(!root) return;
//         TreeNode* curr=root;
//         while(curr)
//         {
//             if(curr->left)
//             {
//                 TreeNode* prev=curr->left;
//                 while(prev->right)
//                 {
//                     prev=prev->right;
//                 }
//                 prev->right=curr->right;
//                 curr->right=curr->left;
//                 curr->left=NULL;

//             }
//             curr=curr->right;
//         }
//     }
