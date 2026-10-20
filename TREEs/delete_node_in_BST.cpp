//MysirG approach?//

// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         TreeNode *ptr,*parptr;
//    if(root==NULL)
//    {
//     return root;
//    }
//    parptr=NULL;
//    ptr=root;
//    while(ptr)
//    {
//       if(ptr->val==key)
//       break;
//       if(key<ptr->val)
//       {
//         parptr=ptr;
//         ptr=ptr->left;
//       }
//       else
//       {
//         parptr=ptr;
//         ptr=ptr->right;
//       }
//    }
//    if(ptr==NULL)
//     return root;

//    if(parptr==NULL && ptr!=NULL) // root node to be deleted 
//    {
//       if(ptr->left==NULL && ptr->right==NULL) // no child case
//       {
//         delete ptr;
//         root=NULL;
//       }
//       else if(ptr->left && ptr->right) // two chid case
//       {
//           TreeNode *suc,*parsuc;
//          suc=ptr->right;
//          parsuc=ptr;
//          while(suc->left!=NULL)
//          {
//             parsuc=suc;
//             suc=suc->left;
//          }
//          ptr->val=suc->val;
//          // now delete successor
         
//             if(suc==parsuc->left)
//               parsuc->left=suc->right;
//             else 
//                parsuc->right=suc->right;
//             delete suc;
//       }
//       else  // one chid case
//       {
//         if(ptr->left)
//              root=ptr->left;
//         else
//              root=ptr->right;
//         delete ptr;

//       }
//    }
//    else  // node to be deleted is not a root node 
//    {
//       if(ptr->left==NULL && ptr->right==NULL) // no child
//       {
//         if(ptr==parptr->left) //ptr is left child of parptr
//         {
//             parptr->left=NULL;
//             delete ptr;
//         }
//         else // ptr is right child of parptr
//         {
//              parptr->right=NULL;
//               delete ptr;
//         }
//       }
//       else if(ptr->left && ptr->right) // two child
//       {
//          TreeNode *suc,*parsuc;
//          suc=ptr->right;
//          parsuc=ptr;
//          while(suc->left!=NULL)
//          {
//             parsuc=suc;
//             suc=suc->left;
//          }
//          ptr->val=suc->val;
//          // now delete successor
         
//             if(suc==parsuc->left)
//               parsuc->left=suc->right;
//             else 
//                parsuc->right=suc->right;
//             delete suc;
         
//       }
//       else // ptr is right child of parptr
//       {
//           if(ptr==parptr->left) //ptr is left child of parptr
//         {
//            if(ptr->left)
//               parptr->left=ptr->left;
//             else
//               parptr->left=ptr->right;
//             delete ptr;
//         }
//         else // ptr is right child of parptr
//         {
//             if(ptr->left)
//                parptr->right=ptr->left;
//             else
//                parptr->right=ptr->right;
//               delete ptr;
//         }
//       }
//    }
//       return root;
        
        
//     }
// };




/// Striver Approach ///
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         TreeNode *ptr,*parptr;
//    if(root==NULL)
//    {
//     return root;
//    }
//    parptr=NULL;
//    ptr=root;
//    while(ptr)
//    {
//       if(ptr->val==key)
//       break;
//       if(key<ptr->val)
//       {
//         parptr=ptr;
//         ptr=ptr->left;
//       }
//       else
//       {
//         parptr=ptr;
//         ptr=ptr->right;
//       }
//    }
//    if(ptr==NULL)
//     return root;

//       if(parptr==NULL && ptr!=NULL )
//       {
//         if(ptr->left && ptr->right)
//         {
//             TreeNode* templeft=ptr->left;
//             TreeNode* curr=templeft;
//             TreeNode* tempright=ptr->right;
//             delete ptr;
//             while(templeft->right!=NULL)
//             {
//                 templeft=templeft->right;
//             }
//             templeft->right=tempright;
//             return curr;

//         }
//         else if(!ptr->left && !ptr->right)
//         {
//             return parptr;
//         }
//         else
//         {
//             if(ptr->left)
//             {
//                 root=ptr->left;
//             }
//             else
//             {
//                root=ptr->right;
//             }
//             delete ptr;
//         }
//       }
//       else
//       {
//         if(ptr==parptr->left)
//         {
//             TreeNode* temp=ptr->left;
//             parptr->left=ptr->right;
//             delete ptr;
//             while(parptr->left!=NULL)
//             {
//                 parptr=parptr->left;
//             }
//             parptr->left=temp;
//         }
//         else
//         {
//             TreeNode* temp=ptr->right;
//             parptr->right=ptr->left;
//             delete ptr;
//             while(parptr->right!=NULL)
//             {
//                 parptr=parptr->right;
//             }
//             parptr->right=temp;
//         }
//       }
//       return root;
        
        
//     }
// };




// DFS Approach //
// class Solution {
// public:
//     TreeNode* findMin(TreeNode* node) {
//         while (node->left != NULL) {
//             node = node->left;
//         }
//         return node;
//     }

//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if (root == NULL) return NULL;

//         if (key < root->val) {
//             root->left = deleteNode(root->left, key);
//         }
//         else if (key > root->val) {
//             root->right = deleteNode(root->right, key);
//         }
//         else {
//             // Node found

//             // Case 1 & 2: 0 or 1 child
//             if (root->left == NULL)
//                 return root->right;
//             if (root->right == NULL)
//                 return root->left;

//             // Case 3: 2 children
//             TreeNode* successor = findMin(root->right);
//             root->val = successor->val;
//             root->right = deleteNode(root->right, successor->val);
//         }
//         return root;
//     }
// };
