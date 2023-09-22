class Solution {
public:
int dp[51][51][51][51];
    int max_pick(int row,int col,int row1,int col1,vector<vector<int>>&grid)
    {
        int m = grid.size(),n=grid[0].size();
        if(row>=0 and row<m and col>=0 and col<n and row1>=0 and row1<m and col1>=0 and col1<n and grid[row][col]!=-1 and grid[row1][col1]!=-1){

        if(row1 == grid.size()-1 and col1==grid[0].size()-1)return grid[row1][col1];
        if(row == grid.size()-1 and col==grid[0].size()-1)return grid[row][col];

        if(dp[row][col][row1][col1]!=-1)return dp[row][col][row1][col1];

        int pick = 0;

        if(row==row1 and col==col1)pick+=grid[row][col];
        else pick+= (grid[row][col] + grid[row1][col1]);

        int one = pick + max_pick(row,col+1,row1+1,col1,grid);
        int two = pick + max_pick(row,col+1,row1,col1+1,grid);
        int three = pick + max_pick(row+1,col,row1+1,col1,grid);
        int four = pick + max_pick(row+1,col,row1,col1+1,grid);

        return dp[row][col][row1][col1] = max({one,two,three,four});
        }
        return INT_MIN;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans = max_pick(0,0,0,0,grid);

        if(ans<0)return 0;
        return ans;
    }
};