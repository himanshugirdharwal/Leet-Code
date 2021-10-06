class Solution {
public:
    
    void dfs(int u,vector<vector<int>> &graph,vector<bool> &rec,vector<bool> &iscycle
                ,vector<bool> &vis)
    {
        vis[u]=true;
        rec[u]=true;
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            
            if(!vis[v])
            dfs(v,graph,rec,iscycle,vis);
            
            if(rec[v] || iscycle[v])
            {
                 iscycle[v]=true;
                 iscycle[u]=true;   
            }
        }
        rec[u]=false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<bool> vis(n,0),rec(n,0),iscycle(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,graph,rec,iscycle,vis);
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(!iscycle[i])ans.push_back(i);
        }
        
        return ans;
        
    }
};
