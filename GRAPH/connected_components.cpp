class Solution {
  public:
    void dfs(int node,vector<vector<int>>& graph,vector<int>& component,vector<bool>& visit)
    {
        visit[node]=true;
        component.push_back(node);
        for(int it:graph[node])
        {
            if(!visit[it])
            {
                dfs(it,graph,component,visit);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        
        vector<bool> visit(V,false);
        vector<vector<int>> ans;
        for(int i=0;i<V;i++)
        {
            vector<int> component;
            if(!visit[i])
            {
                dfs(i,graph,component,visit);
                ans.push_back(component);
            }
        }
        
        
        return ans;
        
        
        
    }
};