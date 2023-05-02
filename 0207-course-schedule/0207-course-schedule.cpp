class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }
        queue<int>q;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        return (count==n);
    }
};