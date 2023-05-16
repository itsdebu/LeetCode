class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]-k])count+=mp[nums[i]-k];
            if(mp[nums[i]+k])count+=mp[nums[i]+k];
            mp[nums[i]]++;
        }return count;
    }
};