class Solution {
public:
    int dp[1001];
    int count_ways(int target,vector<int>&nums)
    {
        if(target==0)return 1;
        if(target<0)return 0;
        if(dp[target]!=-1)return dp[target];
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans+= count_ways(target-nums[i],nums);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return count_ways(target,nums);
    }
};