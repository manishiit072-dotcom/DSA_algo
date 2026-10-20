// class Solution {
//   public:
//     // Function to convert a binary tree into its mirror tree.
//     void interchange(Node* root)
//     {
//         Node* hipe=root;
//         if(!root) return;
//         if(!hipe->left && !hipe->right)
//         {
//             return;
//         }
//         Node* temp=hipe->left;
//         hipe->left=hipe->right;
//         hipe->right=temp;
//         interchange(hipe->left);
//         interchange(hipe->right);
//     }
//     void mirror(Node* node){
//         interchange(node);
        
//     }
// };






// class Solution {
//   public:
//     // Function to convert a binary tree into its mirror tree.
//     void interchange(Node* root)
//     {
//         queue<Node*> q;
//         q.push(root);
//         while(!q.empty())
//         {
//             Node* current=q.front();
//             q.pop();
//             swap(current->left,current->right);
//             if(current->left)
//             {
//                 q.push(current->left);
//             }
//             if(current->right)
//             {
//                 q.push(current->right);
//             }
//         }
//     }
//     void mirror(Node* node){
//         interchange(node);
        
//     }
// };