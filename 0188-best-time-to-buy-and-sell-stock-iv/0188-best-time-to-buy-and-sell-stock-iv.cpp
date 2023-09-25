class Solution {
public:
    int dp[1001][2][101];
    int max_earn(int index,int buy,int k,vector<int>&nums)
    {
        if(k==0)return 0;
        if(index>=nums.size())return 0;
        int max_profit = INT_MIN;

        if(dp[index][buy][k]!=-1)return dp[index][buy][k];

        if(buy)
        {
            max_profit = max(-nums[index] + max_earn(index+1,0,k,nums) , max_earn(index+1,1,k,nums));
        }
        else
        {
            max_profit = max(nums[index] + max_earn(index+1,1,k-1,nums), max_earn(index+1,0,k,nums));
        }
        return dp[index][buy][k] = max_profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return max_earn(0,1,k,prices);
    }
};