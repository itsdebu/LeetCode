class Solution {
public:
    int dp[101][101];
    int unique_ways(int row,int col,int m,int n)
    {
        if(row<0 or col<0 or row>=m or col>=n)return 0;
        if(row==m-1 and col==n-1)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        int right = unique_ways(row,col+1,m,n);
        int down = unique_ways(row+1,col,m,n);

        return dp[row][col] = right+down;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return unique_ways(0,0,m,n);
    }
};