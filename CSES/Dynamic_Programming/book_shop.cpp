#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long n,x;
    cin>>n>>x;
    vector<long long> prices(n),pages(n);
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }
    vector<vector<long long>> dp(n+1,vector<long long>(x+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=x;j++)
        {
            dp[i][j]=dp[i+1][j];
            if(j-prices[i]>=0)
            {
                dp[i][j]=max(dp[i][j],pages[i]+dp[i+1][j-prices[i]]);
            }
        }
    }

    cout<<dp[0][x]<<endl;
}
int main()
{
    solve();
}