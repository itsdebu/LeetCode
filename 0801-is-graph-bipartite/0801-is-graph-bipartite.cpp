class Solution {
public:
    bool check(int node,vector<int>&color,int clr,vector<vector<int>>graph)
    {
        color[node] = clr;

        for(auto it:graph[node])
        {
            if(!color[it])
            {
                if(!check(it,color,!clr,graph))return false;
            }
            if(color[node]==color[it])return false;
        }return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>color(n,0);

        for(int i=0;i<n;i++)
        {
            if(!color[i])
            {
                if(!check(i,color,0,graph))return false;
            }
        }return true;
    }
};