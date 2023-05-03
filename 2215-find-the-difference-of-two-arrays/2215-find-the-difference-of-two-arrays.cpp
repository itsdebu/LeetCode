class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s(nums1.begin(),nums1.end());
        set<int>s1(nums2.begin(),nums2.end());
        map<int,int>v,v1;
        vector<vector<int>>ans;
        for(int i=0;i<nums1.size();i++)
        {
            if(s1.find(nums1[i])==s1.end())v[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(s.find(nums2[i])==s.end())v1[nums2[i]]++;
        }
        vector<int>res;
        for(auto it:v)
        {
            res.push_back(it.first);
        }
        ans.push_back(res);
        res.clear();
        for(auto it:v1)
        {
            res.push_back(it.first);
        }
        ans.push_back(res);
        return ans;
    }
};