#include<bits/stdc++.h>
using namespace std;
set<long long> dp;
void helper(int idx,vector<int>& arr,long long sum)
{
    if(idx==arr.size())
    {
        dp.insert(sum);
        return;
    }
    
    
    helper(idx+1,arr,sum+arr[idx]);
    helper(idx+1,arr,sum);

}
void solve()
{
    int k;
    cin>>k;
    vector<int> arr(k);
    for(int i=0;i<k;i++)
    {
          cin>>arr[i];
    }
   
    helper(0,arr,0);

    dp.erase(0); 
    cout<<dp.size()<<endl;

    for(auto& it:dp)
    {
        cout<<it<<" ";
    }
}
int main(){
    solve();
    return 0;
}