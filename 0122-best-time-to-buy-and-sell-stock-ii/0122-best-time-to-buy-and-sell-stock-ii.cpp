class Solution {
public:
    int max_profit(int index,vector<int>&nums,int buy,vector<vector<int>>&dp)
    {
        if(index==nums.size())return 0;
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit=INT_MIN;
        if(buy)
        {
            profit=max(-nums[index]+max_profit(index+1,nums,0,dp),max_profit(index+1,nums,1,dp));
        }
        else
        {
            profit=max(nums[index]+max_profit(index+1,nums,1,dp),max_profit(index+1,nums,0,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return max_profit(0,prices,1,dp);
    }
};