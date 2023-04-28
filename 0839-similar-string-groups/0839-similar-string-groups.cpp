class Solution {
public:
    bool check(string a, string b)
    {
        int count=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])count++;
        }
        if(count<=2)return true;
        return false;
    }
    void dfs(int node,vector<int>&vis,vector<vector<int>>adj)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>>adj(strs.size());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                count++;
            }
        }return count;
    }
};