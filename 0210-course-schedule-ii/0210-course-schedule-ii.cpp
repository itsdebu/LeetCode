class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& grid) {
        vector<int>adj[n];
        for(auto i:grid)
        {
            adj[i[0]].push_back(i[1]);
        }
        vector<int>Indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
                Indegree[it]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(Indegree[i]==0)q.push(i);
        }
        vector<int>ans;
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
        }reverse(ans.begin(),ans.end());
        if(ans.size()==n)return ans;
        return {};
    }
};