class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(nums.size(),0);
        dp[n-1]=1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            int mx=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]>nums[i])
                {
                    mx=max(mx,dp[j]);
                }
            }
            dp[i]=1+mx;
        }
        return *max_element(dp.begin(),dp.end());
    }
};