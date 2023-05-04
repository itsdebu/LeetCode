class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>>q;
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        q.push({k,0});
        while(!q.empty())
        {
            int node=q.front().first;
            int wt=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int adjwt=it.second;
                if(wt+adjwt<dist[adjnode])
                {
                    dist[adjnode]=wt+adjwt;
                    q.push({adjnode,dist[adjnode]});
                }
            }
        }
        int mx=INT_MIN;
        for(int i=1;i<dist.size();i++)
        {
            if(mx<dist[i])mx=dist[i];
        }
        if(mx==INT_MAX)return -1;
        return mx;
    }
};