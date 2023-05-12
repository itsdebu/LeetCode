class Solution {
public:
    long long mostPoints(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<long long>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int points=nums[i][0];
            int jump=nums[i][1];
            int nextQuestion = min(n, i+jump+1);
            dp[i] = max(dp[i+1], points + dp[nextQuestion]);
        }return dp[0];
    }
};