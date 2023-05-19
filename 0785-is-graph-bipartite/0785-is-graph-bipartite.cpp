class Solution {
public:
    bool dfs(int node,vector<int>&color,vector<vector<int>>graph,int col)
    {
        color[node]=col;
        for(auto it:graph[node])
        {
            if(!color[it])
            {
                if(!dfs(it,color,graph,!col))return false;
            }
            if(color[node]==color[it])return false;
        }return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        int col=0;
        for(int i=0;i<n;i++)
        {
            if(!color[i])
            {
                if(!dfs(i,color,graph,col))return false;
            }
        }return true;
    }
};