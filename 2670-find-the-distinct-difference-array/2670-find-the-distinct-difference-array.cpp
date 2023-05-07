class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp,mp1;
        for(int i=0;i<nums.size();i++)mp1[nums[i]]++;
        vector<int>diff;
        for(int i=0;i<n;i++)
        {
            mp1[nums[i]]--;
            if(mp1[nums[i]]==0)mp1.erase(nums[i]);
            mp[nums[i]]++;
            diff.push_back(mp.size()-mp1.size());
        }return diff;
    }
};