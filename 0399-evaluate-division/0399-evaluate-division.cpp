class Solution {
public:
   void dfs(string src, string dest, set<string> &vis, unordered_map<string, vector<pair<string, double>>> &mp, double temp, double &ans) 
    {
        if (vis.find(src) != vis.end()) {
            return;
        }

        vis.insert(src);


        if (src == dest) {
            ans = temp;
            return;
        }

        for (auto curr: mp[src]) {
            dfs(curr.first, dest, vis, mp, temp * curr.second, ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        int i = 0;

        for (auto equation: equations) {
            mp[equation[0]].push_back({equation[1], values[i]});
            mp[equation[1]].push_back({equation[0], 1/values[i]});
            i++;
        }

        i = 0;

        vector<double> res;

        for (auto query: queries) {

            double ans = -1.0;

            if (mp.find(query[0]) != mp.end()) {
                set<string> vis;
                dfs(query[0], query[1], vis, mp,1,ans);
            }

            res.push_back(ans);

        }

        return res;
    }
};