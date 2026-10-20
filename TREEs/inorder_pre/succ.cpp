// class Solution {
//   public:
//     vector<Node*> findPreSuc(Node* root, int key) {
//         Node *successor=NULL,*predecessor=NULL;
//         vector<Node*> ans;
//         if(!root) return ans;
//         Node* suc=root;
//         Node* pre=root;
//         while(suc!=NULL)
//         {
//             if(key>=suc->data)
//             {
//                 suc=suc->right;
//             }
//             else
//             {
//                 successor=suc;
//                 suc=suc->left;
//             }
//         }
        
//         while(pre!=NULL)
//         {
//             if(key<=pre->data)
//             {
//                 pre=pre->left;
                
//             }
//             else
//             {
//                 predecessor=pre;
//                 pre=pre->right;
//             }
//         }
//         ans.push_back(predecessor);
//         ans.push_back(successor);
//         return ans;
//     }
// };