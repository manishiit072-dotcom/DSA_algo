#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int helper(int i,int j,vector<vector<char>> & grid,int n,vector<vector<int>>& dp)
{
    if(i>=n || j>=n || grid[i][j]=='*')
    {
        return 0;
    }
    if(i==n-1 && j==n-1)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j]%MOD;
    }

    int left=helper(i+1,j,grid,n,dp);
    int right=helper(i,j+1,grid,n,dp);

    return dp[i][j]=(left+right)%MOD;
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

    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<helper(0,0,grid,n,dp)%MOD<<endl;



}

int main()
{
    solve();

}