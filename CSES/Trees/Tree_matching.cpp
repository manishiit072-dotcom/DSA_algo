#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> edges(n+1);
    for(int i=2;i<=n;i++)
     {
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
     }

     
     cout<<dist<<endl;
     return 0;
}