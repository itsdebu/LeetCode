class Solution {
public:
    int dp[501][501];
    int minDistance(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        int n=s1.size(),m=s2.size();
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                    
            }
        }return dp[n][m];
    }
};