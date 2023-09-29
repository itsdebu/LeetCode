class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
				vector<vector<int>>adj(n);

				vector<int>Indegree(n,0);

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
				for(int i=0;i<n;i++)
				{
					if(Indegree[i]==0)q.push(i);
				}
				vector<int>res;
				while(!q.empty())
				{
						int node = q.front();
						q.pop();
						res.push_back(node);
						for(auto it:adj[node])
						{
								Indegree[it]--;
								if(Indegree[it]==0)q.push(it);
						}
				}sort(res.begin(),res.end());
				return res;
    }
};