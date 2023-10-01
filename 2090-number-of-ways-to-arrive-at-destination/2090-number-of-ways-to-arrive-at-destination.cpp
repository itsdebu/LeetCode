class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<pair<int, int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // Using Dijkstra's {time, node}
        priority_queue<pair<long, long>, vector<pair<long, long>>, 
                    greater<pair<long, long>>> q;
        q.push({0, 0});
        
        vector<long> dist(n, LONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)1e9 + 7;
        while(!q.empty()){
            int node=q.top().second;
            long dis=q.top().first;
            q.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int adjwt=it.second;
                if(dis+adjwt<dist[adjnode])
                {
                    dist[adjnode]=dis+adjwt;
                    q.push({dist[adjnode],adjnode});
                    ways[adjnode]=ways[node]%mod;
                }
                else if(adjwt+dis==dist[adjnode])
                {
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }return ways[n-1]%mod; 
    }
};