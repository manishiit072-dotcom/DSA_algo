// class Solution {
//     public:
//       // Function to check whether a Binary Tree is BST or not.
//       bool BST(Node* root,int min,int max)
//       {
//           if(!root)
//           {
//               return true;
//           }
          
//           if(root->data<min || root->data>max)
//           {
//               return false;
//           }
          
//           return BST(root->left,min,root->data-1) && BST(root->right,root->data+1,max);
//       }
      
//       bool isBST(Node* root) {
         
          
//           return BST(root,INT_MIN,INT_MAX);
//       }
//   };





// class Solution {
//     public:
//       // Function to check whether a Binary Tree is BST or not.
//       bool inorderTraversal(Node* root,int* prev)
//       {
//           if(!root)
//           {
//               return true;
//           }
          
//           if(!inorderTraversal(root->left,prev))
//           {
//               return false;
//           }
          
//           if(*prev>=root->data)
//           {
//               return false;
//           }
          
//           *prev=root->data;
          
//           return inorderTraversal(root->right,prev);
//       }
      
//       bool isBST(Node* root) {
//           int prev=INT_MIN;
         
//           return inorderTraversal(root,&prev);
          
//       }
//   };