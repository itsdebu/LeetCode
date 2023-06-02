class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int count=1;count<=2;count++)
                {
                    if(buy==1)
                    {
                        dp[index][buy][count]=max(-nums[index]+dp[index+1][0][count],dp[index+1][1][count]);
                    }
                    else
                    {
                        dp[index][buy][count]=max(nums[index]+dp[index+1][1][count-1],dp[index+1][0][count]);
                    }
                }
            }
        }return dp[0][1][2];
    }
};