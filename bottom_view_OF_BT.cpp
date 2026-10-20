// class Solution {
//   public:
//     vector<int> bottomView(Node *root) {
//         vector<int> ans;
//         if(!root) return ans;
//         map<int,int> m;
//         queue<pair<Node*,int>> q;
//         q.push({root,0});
//         while(!q.empty())
//         {
//             auto curr=q.front();
//             q.pop();
//             Node* node=curr.first;
//             int distance=curr.second;
//             if(m.find(distance)==m.end()){
//                  m[distance]=node->data;
//             }
//             if(m.find(distance)!=m.end()){
//                  m[distance]=node->data;
//             }
            
            
//             if(node->left){
//                 q.push({node->left,distance-1});
//             } 
        
//             if(node->right){ 
//                 q.push({node->right,distance+1});
//             }
//         }
        
//         for(auto it:m)
//         {
//             ans.push_back(it.second);
//         }
        
//         return ans;
//     }
// };