class Solution {
public:
    int dp[50001][2];
    int max_earn(int index,int fee,int buy,vector<int>&nums)
    {
        if(index>=nums.size())return 0;

        if(dp[index][buy]!=-1)return dp[index][buy];

        int max_profit = INT_MIN;

        if(buy)
        {
            max_profit = max(-nums[index] + max_earn(index+1,fee,0,nums) , max_earn(index+1,fee,1,nums));
        }
        else
        {
            max_profit = max((nums[index] - fee) + max_earn(index+1,fee,1,nums) , max_earn(index+1,fee,0,nums));
        }
        return dp[index][buy] = max_profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return max_earn(0,fee,1,prices);
    }
};