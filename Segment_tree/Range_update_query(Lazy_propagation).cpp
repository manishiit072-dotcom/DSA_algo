#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> segTree(4*N,0),lazyTree(4*N,0);
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
void updateRange(int start,int end,int i,int l,int r,int val)
{
    if(lazyTree[i]!=0)
    {
        segTree[i]+=(r-l+1)*lazyTree[i];
        if(l!=r)
        {
            lazyTree[2*i+1]+=lazyTree[i];
            lazyTree[2*i+2]+=lazyTree[i];
        }
        lazyTree[i]=0;
    }

    // out of range
    if(start>r || end<l || l>r)
    {
        return;
    }

    // complete overlapping of range
    if(start<=l && end>=r)
    {
        segTree[i]+=(r-l+1)*val;
        if(l!=r)
        {
            lazyTree[2*i+1]+=val;
            lazyTree[2*i+2]+=val;
        }
        return;
    }

    int mid=l+(r-l)/2;
    updateRange(start,end,2*i+1,l,mid,val);
    updateRange(start,end,2*i+2,mid+1,end,val);
    
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
    buildsegTree(arr,0,0,n-1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int start,end,val;
        cin>>start>>end>>val;
        updateRange(start,end,0,0,n-1,val);
    }

    return 0;

}