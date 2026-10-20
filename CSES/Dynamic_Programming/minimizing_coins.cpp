#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    vector<int> dp(x+1,0);
    dp[0]=0;

    for(int i=1;i<=x;i++)
    {
        int ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
               if(i-coins[j]>=0)
               {
                 int res=dp[i-coins[j]];
                 if(res!=INT_MAX)
                 {
                    ans=min(ans,res+1);
                 }
               }
        }
        dp[i]=ans;
    }
    


    if(dp[x]==INT_MAX)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<dp[x]<<endl;
    }
}

int main()
{
    solve();
}