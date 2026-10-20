// class Solution {
//   public:
//     // Function to return a list of integers denoting the node
//     // values of both the BST in a sorted order.
//     void inorder(Node* root,vector<int>& ans)
//     {
//         if(root)
//         {
//             inorder(root->left,ans);
//             ans.push_back(root->data);
//             inorder(root->right,ans);
//         }
//     }
//     vector<int> merge(Node *root1, Node *root2) {
//        vector<int> vec1,vec2,ans;
//        if(!root1 && !root2) return ans;
//        inorder(root1,vec1);
//        inorder(root2,vec2);
//        int m=vec1.size();
//        int n=vec2.size();
//        int i=0,j=0;
//        while(i<m && j<n)
//        {
//            if(vec1[i]>=vec2[j])
//            {
//                ans.push_back(vec2[j]);
//                j++;
//            }
//            if(vec1[i]<vec2[j])
//            {
//                ans.push_back(vec1[i]);
//                i++;
//            }
//        }
//        while(i<m)
//        {
//            ans.push_back(vec1[i]);
//            i++;
//        }
//         while(j<n)
//        {
//            ans.push_back(vec2[j]);
//            j++;
//        }
       
       
//        return ans;
        
//     }
// };