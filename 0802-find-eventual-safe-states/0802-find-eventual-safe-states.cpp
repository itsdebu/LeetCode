class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>Indegree(n);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                Indegree[it]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(Indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                Indegree[it]--;
                if(Indegree[it]==0)q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};