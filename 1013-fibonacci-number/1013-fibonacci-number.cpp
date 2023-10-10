class Solution {
public:
    int dp[31];
    int fib(int n) {
        memset(dp,-1,sizeof(dp));
        if(n<=1)return n;

        return dp[n] = fib(n-1) + fib(n-2);
    }
};