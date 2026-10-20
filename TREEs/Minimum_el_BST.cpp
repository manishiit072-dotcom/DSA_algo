// class Solution {
//     public:
//     int min_el(Node* root)
//     {
//         if(root->left==NULL) return root->data;
        
//         return min_el(root->left);
//     }
//       int minValue(Node* root) {
//           if(root==NULL) return -1;
//           return min_el(root);
//       }
//   };