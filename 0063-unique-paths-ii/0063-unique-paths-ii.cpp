class Solution {
public:
    int dp[101][101];
    int total_path(int i,int j,int m,int n,vector<vector<int>>&grid)
    {
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]==1)return 0;
        if(i==m-1 and j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=total_path(i+1,j,m,n,grid)+total_path(i,j+1,m,n,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m=grid.size(),n=grid[0].size();
        return total_path(0,0,m,n,grid);
    }
};