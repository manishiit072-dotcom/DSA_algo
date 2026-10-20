#include<bits/stdc++.h>
using namespace std;
long long helper(int digit,long long num,long long a,long long b,vector<vector<long long>>& dp)
{
    if(num>=a && num<=b)
    {
        return 1;
    }
    if(num>b)
    {
        return 0;
    }
    if(dp[digit][num]!=-1) return dp[digit][num];

    long long count=0;
    for(int i=0;i<=9;i++)
    {
        if(i!=digit){
        count+=helper(i,num*10+i,a,b,dp);
        }
    }

    return dp[digit][num]=count;
}
void solve()
{
    long long a,b;
    cin>>a>>b;
    vector<vector<long long>> dp(10,vector<long long>(b+1,-1));

    

    cout<<helper(1,1,a,b,dp)<<endl;
}
int main()
{
    solve();
    return 0;
}