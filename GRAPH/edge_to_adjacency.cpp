#include<iostream>
#include<vector>
using namespace std;
int main()
{
   vector<vector<int>> edges={{0,1},{1,2},{2,3},{0,2},{1,3}};
   vector<vector<int>> adj(edges.size());
   for(auto edge:edges)
   {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
   }

   for(auto it:adj)
   {
    for(int curr:it)
    {
        cout<<curr<<" ";
    }
    cout<<endl;
   }
}