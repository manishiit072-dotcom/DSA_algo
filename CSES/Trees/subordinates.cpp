#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>& tree,vector<int>& sub)
{
    for(auto child:tree[node])
    {
        dfs(child,tree,sub);
        sub[node]+=1+sub[child];

    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> subordinates(n+1,0);
    vector<vector<int>> tree(n+1);
    for(int i=2;i<=n;i++)
    {
        int boss;
        cin>>boss;
        tree[boss].push_back(i);
    }

    dfs(1,tree,subordinates);


    for(int i=1;i<=n;i++)
    {
        cout<<subordinates[i]<<" ";
    }

    return 0;






}