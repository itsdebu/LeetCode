class Solution {

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &cnt){
        vis[node] = 1;
        
        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, cnt);
                cnt++;
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> vis(n);
        vector<vector<int>> adj(n);
        
        for(auto i : edges)
        {   
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        } 
        
        vector<int> v;
        int cnt = 1;
        for(int i = 0 ;i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis, cnt);
                v.push_back(cnt);
                cnt = 1;
            }    
        }
        // for(auto i:v)cout<<i<<" ";
        if(v.size() == 1) return 0; 
        long long ans = 0, sum = 0;
        
        for(int i = 0;i < v.size();i++){
            ans += (sum * v[i]);
            sum += v[i];
            // cout<<ans<<endl;
        }
        return ans;
    }
};