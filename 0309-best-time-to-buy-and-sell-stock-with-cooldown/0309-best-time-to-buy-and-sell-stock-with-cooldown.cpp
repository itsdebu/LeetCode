class Solution {
public:
    int dp[5001][2];
    int max_profit(int index,vector<int>&nums,int buy)
    {
        if(index>=nums.size())return 0;
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit=INT_MIN;
        if(buy)
        {
            profit=max(-nums[index]+max_profit(index+1,nums,0),max_profit(index+1,nums,1));
        }
        else
        {
            profit=max(nums[index]+max_profit(index+2,nums,1),max_profit(index+1,nums,0));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return max_profit(0,prices,1);
    }
};