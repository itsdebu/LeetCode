class Solution {
public:
    int max_rob(int n,vector<int>nums,vector<int>&dp)
    {
        if(n==0)return nums[0];
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int one_jump=max_rob(n-1,nums,dp);
        int two_jump=nums[n]+max_rob(n-2,nums,dp);
        return dp[n]= max(one_jump,two_jump);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return max_rob(nums.size()-1,nums,dp);
    }
};