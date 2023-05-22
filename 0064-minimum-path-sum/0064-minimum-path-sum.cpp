class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid){    //////// function declaration
    //base case
    if(i==0 && j==0)
    return grid[0][0];

        if(i<0 || j<0)
            return INT_MAX;

        //check
        if(dp[i][j]!=-1)
            return dp[i][j];

        //recurrence relation
        int up = solve(i-1,j,dp,grid);
        int left =solve(i,j-1,dp,grid);
        return dp[i][j]=grid[i][j]+min(up,left);           /////// correct way to return , you need not add grid[i][j] direct;y in solve(i-1, j)/solve(i, j-1) , bcz solve() can return INT_MAX;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,grid);
    }
};