class Solution {
public:
    bool dfs(int node,vector<vector<int>>graph,vector<int>&color,int col)
    {
        color[node]=col;
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                if(!(dfs(it,graph,color,!col)))return false;
            }
            else if(color[it]==color[node])return false;
        }return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(!dfs(i,graph,color,1))return 0;
	        }
	    }return true;
    }
};