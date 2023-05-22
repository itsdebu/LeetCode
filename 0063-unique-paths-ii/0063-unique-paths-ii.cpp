class Solution {
public:
    int dp[101][101];
    int all_path(int i,int j,vector<vector<int>>grid)
    {
        if(i>=grid.size() or j>=grid[0].size() or grid[i][j]==1)return 0;
        if(i==grid.size()-1 and j==grid[0].size()-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int right=all_path(i+1,j,grid);
        int down=all_path(i,j+1,grid);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return all_path(0,0,grid);
    }
};