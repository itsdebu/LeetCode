class Solution {
public:
    int dp[201][201];
    int min_path(int i,int j,int m, int n,vector<vector<int>>&grid)
    {
        if(i<0 or j<0 or i>=m or j>=n)return 1e8;
        if(i==m-1 and j==n-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = grid[i][j] + min(min_path(i+1,j,m,n,grid),min_path(i,j+1,m,n,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return min_path(0,0,m,n,grid);
    }
};