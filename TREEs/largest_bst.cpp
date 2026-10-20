// /class Solution {
//   public:
//     /*You are required to complete this method */
//     // Return the size of the largest sub-tree which is also a BST
//     bool check(Node* root,int min,int max)
//     {
//         if(!root) return true;
        
//         if(root->data<min || root->data>max)
//         {
//             return false;
            
//         }
        
//         return check(root->left,min,root->data-1) && check(root->right,root->data+1,max);
//     }
//     int size(Node* root)
//     {
//         if(!root) return 0;
        
//         return 1+size(root->left)+size(root->right);
//     }
//     int largestBst(Node *root) {
//         if(!root) return 0;
        
//         if(check(root,INT_MIN,INT_MAX))
//         {
//             return size(root);
//         }
        
//         return max(largestBst(root->left),largestBst(root->right));
        
//     }
// };