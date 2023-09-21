class Solution {
public:
    int dp[45 + 1];
    int count_steps(int n)
    {
        if(n<=3)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n] =  count_steps(n-1) + count_steps(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return count_steps(n);
    }
};