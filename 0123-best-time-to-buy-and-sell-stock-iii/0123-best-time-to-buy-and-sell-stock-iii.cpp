class Solution {
public:
    int dp[100001][2][3];
    int max_profit(int index,vector<int>&nums,int buy,int count)
    {
        if(count==0)return 0;
        if(index==nums.size())return 0;
        if(dp[index][buy][count]!=-1)return dp[index][buy][count];
        int profit=INT_MIN;
        if(buy)
        {
            profit=max(-nums[index]+max_profit(index+1,nums,0,count),max_profit(index+1,nums,1,count));
        }
        else
        {
            profit=max(nums[index]+max_profit(index+1,nums,1,count-1),max_profit(index+1,nums,0,count));
        }
        return dp[index][buy][count]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return max_profit(0,prices,1,2);
    }
};