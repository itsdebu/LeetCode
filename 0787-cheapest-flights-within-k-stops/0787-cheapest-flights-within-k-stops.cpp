class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& grid, int src, int dst, int k) {
        queue<pair<pair<int,int>,int>>q;
        vector<int>dist(n,INT_MAX);
        vector<pair<int,int>>adj[n];
        for(auto it:grid)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        dist[src]=0;
        q.push({{src,0},0});
        while(!q.empty())
        {
            int node=q.front().first.first;
            int dis=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            if(steps>k)continue;
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int adjwt=it.second;
                if(dis+adjwt<dist[adjnode])
                {
                    dist[adjnode]=dis+adjwt;
                    q.push({{adjnode,dist[adjnode]},steps+1});
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};