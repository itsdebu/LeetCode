class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> win;
        unordered_map<int,int> loss;
        for(int i=0;i<matches.size();i++){
            win[matches[i][0]]++;
            loss[matches[i][1]]++;
        }
        vector<int> f,s;
        for(auto it: loss){
            if(it.second==1)
                s.push_back(it.first);
        }
        for(auto it: win){
            if(loss.count(it.first)==0)
                f.push_back(it.first);
        }
        sort(f.begin(),f.end());
        sort(s.begin(),s.end());
        vector<vector<int>> ans;
        ans.push_back(f);
        ans.push_back(s);
        return ans;
    }
};