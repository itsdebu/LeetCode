class Solution {
public:
    int max_earn(int index,vector<int>&nums,vector<int>&dp)
    {
        if(index>=nums.size())return 0;
        if(index==nums.size())return nums[index];
        if(dp[index]!=-1)return dp[index];
        int not_take=max_earn(index+1,nums,dp);
        int take=nums[index]+max_earn(index+2,nums,dp);
        return dp[index]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return max_earn(0,nums,dp);
    }
};