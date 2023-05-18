class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
        }
        vector<int>Indegree(n,0);
        for(int i=0;i<n;i++)
        {   
            for(auto it:adj[i])
            {
                Indegree[it]++;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(Indegree[i]==0)ans.push_back(i);
        }return ans;
    }
};