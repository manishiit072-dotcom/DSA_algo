#include<bits/stdc++.h>
using namespace std;
void helper(int i,int j,string part,vector<vector<char>>& grid,vector<string>& ans)
{
    if(i==0 && j==0)
    {
        part+=grid[i][j];
        ans.push_back(part);
        return;
        
    }
    part+=grid[i][j];
    if(i>0)
    {
        helper(i-1,j,part,grid,ans);
    }
    part.pop_back();
    if(j>0)
    {
        helper(i,j-1,part,grid,ans);
    }
    part.pop_back();


}
void solve()
{
    int n;
    cin>>n;

    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
        cout<<endl;
    }
    
    string str="";
    cout<<helper(n-1,n-1,str,n,grid)<<endl;

}
int main()
{
    solve();
    return 0;
}