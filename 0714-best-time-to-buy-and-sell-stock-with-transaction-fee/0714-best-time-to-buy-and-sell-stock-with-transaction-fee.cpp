class Solution {
public:
    int max_profit(int index,vector<int>&nums,int buy,int fee,vector<vector<int>>&dp)
    {
        if(index>=nums.size())return 0;
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit=INT_MIN;
        if(buy)
        {
            profit=max(-nums[index]+max_profit(index+1,nums,0,fee,dp),max_profit(index+1,nums,1,fee,dp));
        }
        else
        {
            profit=max((nums[index]-fee)+max_profit(index+1,nums,1,fee,dp),max_profit(index+1,nums,0,fee,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return max_profit(0,prices,1,fee,dp);
    }
};