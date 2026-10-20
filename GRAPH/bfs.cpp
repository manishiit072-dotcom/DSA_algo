#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    vector<vector<int>> vec={{2,3,1},{0},{0,4},{0},{2}};
    int n=vec.size();
    vector<int> ans;
    vector<bool> visit(n,false);
    queue<int> q;
    q.push(0);
    visit[0]=true;
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        ans.push_back(current);
        for(int neighbours:vec[current])
        {
            if(!visit[neighbours])
            {
                q.push(neighbours);
                visit[neighbours]=true;
            }
        }
    }

    for(int val:ans)
    {
        cout<<val<<" ";
    }

    return 0;

}