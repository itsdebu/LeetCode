class Solution {
public:

		bool iscycle(int node,vector<int>&vis,vector<int>&path,vector<vector<int>>&graph)
		{
				vis[node] = 1;
				path[node] = 1;

				for(auto it:graph[node])
				{
					if(!vis[it])
					{
						if(iscycle(it,vis,path,graph))return true;
					}
					else if(vis[it] and path[it])
					{
						return true;
					}
				}
				path[node] = 0;
				return false;
		}

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
				int n =graph.size();
				vector<int>vis(n,0);
				vector<int>path(n,0);

				for(int i=0;i<n;i++)
				{
						if(!(iscycle(i,vis,path,graph)))
							{
								ans.push_back(i);
							}
				}
				return ans;
    }
};