class Solution {
public:
    void dfs(int node,int &ans,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[abs(it)])
            {
                if(it>0)ans++;
                dfs(abs(it),ans,vis,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>vis(n+1,0);
        vector<vector<int>>adj(n+1);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<" ";
            cout<<endl;
        }
        int ans=0;
        dfs(0,ans,vis,adj);
        return ans;
        
    }
};