#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
void solve(){
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=6;j++)
        {
             ans+=(i-j>=0)?dp[i-j]:0;
             ans%=MOD;

        }
        dp[i]=ans;
    }

    cout<<dp[n]<<endl;

}
int main()
{
    solve();
    
}