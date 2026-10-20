#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int temp=i;
        int ans=INT_MAX;
        while(temp>0)
        {
            int digits=temp%10;
            if(digits!=0)
            {
                int res=dp[i-digits];
                if(res!=INT_MAX)
                {
                    ans=min(ans,res+1);
                }
            }
            temp/=10;
        }
        dp[i]=ans;
    }

    dp[n]==INT_MAX?cout<<-1<<endl:cout<<dp[n]<<endl;

}
int main()
{
    solve();
}