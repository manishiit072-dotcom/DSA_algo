#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> segTree(4*N,0);
void buildsegTree(vector<int>& arr,int i,int l,int r)
{
    if(l==r)
    {
        segTree[i]=arr[i];
        return;
    }
    int mid=l+(r-l)/2;
    buildsegTree(arr,2*i+1,l,mid);
    buildsegTree(arr,2*i+2,mid+1,r);

    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}
int main()
{
    int n;
    cin>>n;
    N=n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    buildsegTree(arr,0,0,N-1);
    return 0;
}