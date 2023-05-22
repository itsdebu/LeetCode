class Solution {
public:
    int All_path(int i,int j,int m,int n,vector<vector<int>>&dp)
    {
        if(i>=m or j>=n)return 0;
        if(i==m-1 and j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int right=All_path(i+1,j,m,n,dp);
        int down=All_path(i,j+1,m,n,dp);
        return dp[i][j]=right+down;
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return All_path(0,0,m,n,dp);
    }
};