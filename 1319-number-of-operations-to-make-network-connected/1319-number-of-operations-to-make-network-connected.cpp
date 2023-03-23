class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])dfs(it,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& nums) {
        vector<int>vis(n,0);
        unordered_map<int,vector<int>> adj;
        int connected=0;
        for(int i=0;i<nums.size();i++)
        {
            adj[nums[i][0]].push_back(nums[i][1]);
            adj[nums[i][1]].push_back(nums[i][0]);
            connected++;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                count++;
                dfs(i,adj,vis);
            }
        }
        
        int left_comp=connected-(n-1-(count-1));
        if(left_comp>=count-1)return count-1;
        return -1;
        
    }
};