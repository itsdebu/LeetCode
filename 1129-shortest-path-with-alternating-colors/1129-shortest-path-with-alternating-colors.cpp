class Solution {
private:
    vector <vector<pair<int,int>>> g;
    vector <int> visCount;
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        g.resize(n);
        visCount.resize(n, 0);
        
        for(const auto e : red_edges) {
            int u = e[0], v = e[1];
            g[u].push_back({ v, 1 }); // RED
        }
        
        for(const auto e : blue_edges) {
            int u = e[0], v = e[1];
            g[u].push_back({ v, -1 }); // BLUE
        }
        
        vector <int> ans(n, INT_MAX);
        queue <pair<int, pair<int, int>>> q;
        
        q.push({ 0, { 0, 0 } });
        visCount[0] += 1;
        
        while(!q.empty()) {
            int node = q.front().first;
            int prevEdgeColor = q.front().second.first, dist = q.front().second.second;
            
            ans[node] = min(ans[node], dist);
            q.pop();
            
            for(const auto ng : g[node]) {
                int ngNode = ng.first, ngColor = ng.second;
				
				// setting hard limit on number of times a node can be visited since we allow loops
                if(prevEdgeColor != ngColor and visCount[ngNode] <= n) {
                    q.push({ ngNode, { ngColor, dist + 1 }});
                    visCount[ngNode] += 1;
                }
            } 
        }
        
        for(int &el : ans) {
            if(el == INT_MAX) {
                el = -1;
            }
        }
        
        return ans;
    }
};