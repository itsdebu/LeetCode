class Solution {
public:
    int dp[101][101];
    int total_path(int i,int j,int m,int n)
    {
        if(i<0 or i>=m or j<0 or j>=n)return 0;
        if(i==m-1 and j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=total_path(i+1,j,m,n)+total_path(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return total_path(0,0,m,n);
    }
};