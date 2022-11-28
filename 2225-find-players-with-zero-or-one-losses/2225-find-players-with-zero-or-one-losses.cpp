class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& nums) {
        unordered_map<int,int>w,l;
        for(int i=0;i<nums.size();i++)
        {
            w[nums[i][0]]++;
            l[nums[i][1]]++;
        }
        vector<int>v,v1;
        for(auto i:l)
        {
            if(i.second==1)v.push_back(i.first);
        }
        for(auto i:w)
        {
            if(l.count(i.first)==0)v1.push_back(i.first);
        }
        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end());
        vector<vector<int>>res;
        res.push_back(v1);
        res.push_back(v);
        return res;
    }
};