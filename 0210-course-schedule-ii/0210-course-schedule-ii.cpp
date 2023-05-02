class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        vector<int>adj[n];
        for(auto it:graph)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<int>ans;
        queue<int>q;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])indegree[it]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==n)return ans;
        return {};
    }
};