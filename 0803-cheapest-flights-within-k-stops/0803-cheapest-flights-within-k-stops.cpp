class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];

        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
            // cout<<adj[it.first]<<endl;
        }

        queue<pair<int,pair<int,int>>>q;

        q.push({0,{src,0}});

        vector<int>dist(n,INT_MAX);

        dist[src] = 0;

        while(!q.empty())
        {
            int steps = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();    

            if(steps>k)continue;

            for(auto it:adj[node])
            {
                int adj_node = it.first;
                int adj_price = it.second;
                if(dist[adj_node]>price + adj_price)
                {
                    dist[adj_node] = price + adj_price;
                    q.push({steps+1,{adj_node,dist[adj_node]}});
                }
            }

        }if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};