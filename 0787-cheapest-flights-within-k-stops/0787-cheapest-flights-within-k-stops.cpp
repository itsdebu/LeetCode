class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto flight:flights)
        {
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!q.empty())
        {
            int node=q.front().second.first;
            int dis=q.front().second.second;
            int stop=q.front().first;
            q.pop();
            if(stop>k)continue;
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int adjwt=it.second;
                if(dis+adjwt<dist[adjnode])
                {
                    dist[adjnode]=dis+adjwt;
                    q.push({stop+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};