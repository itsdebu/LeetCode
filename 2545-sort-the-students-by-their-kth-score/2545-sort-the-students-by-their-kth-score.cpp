class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<score.size();i++)
        {
            v.push_back(make_pair(score[i][k],i));
        }sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<vector<int>>ans;
        for(int i=0;i<score.size();i++)
        {
            int kk=v[i].second;
            ans.push_back(score[kk]);
        }
        return ans;
    }
};