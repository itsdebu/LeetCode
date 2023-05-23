class Solution {
public:
    int solve(vector<vector<int>>& grid, int r1, int c1, int r2, int c2, int n, int m, vector<vector<vector<vector<int>>>>& dp) {
        // check if both current positions are within the grid and not on a thorn
        if (r1 >= 0 && r2 >= 0 && c1 >= 0 && c2 >= 0 && r1 < n && r2 < n && c1 < m && c2 < m && grid[r1][c1] != -1 && grid[r2][c2] != -1) {
            // check if the result has already been calculated and stored in the dp array
            if (dp[r1][c1][r2][c2] != -1)
                return dp[r1][c1][r2][c2];
                
            // base case: if either of the current positions is at the destination cell, return the value of that cell
            if (r1 == n - 1 && c1 == m - 1)
                return grid[r1][c1];
            if (r2 == n - 1 && c2 == m - 1)
                return grid[r2][c2];
            
            int cherry = 0;
            
            // if the two current positions are the same, add the value of that cell to the cherry count
            // otherwise, add the values of both cells to the cherry count
            if (r1 == r2 && c1 == c2)
                cherry += grid[r1][c1];
            else
                cherry += (grid[r1][c1] + grid[r2][c2]);
            
            // calculate the maximum number of cherries by moving both positions in each of the four possible directions
            // and store the result in the dp array
            int op1 = solve(grid, r1, c1 + 1, r2, c2 + 1, n, m, dp);
            int op2 = solve(grid, r1 + 1, c1, r2 + 1, c2, n, m, dp);
            int op3 = solve(grid, r1 + 1, c1, r2, c2 + 1, n, m, dp);
            int op4 = solve(grid, r1, c1 + 1, r2 + 1, c2, n, m, dp);
            return dp[r1][c1][r2][c2] = (cherry += max({op1, op2, op3, op4}));
        }
        // return minimum integer value if the current positions are not valid
        return INT_MIN;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        // initialize dp array with minimum integer value
        vector<vector<vector<vector<int>>>> 
                    dp(grid.size(), vector<vector<vector<int>>>(grid.size(), vector<vector<int>>
                                (grid.size(), vector<int>(grid.size(), -1))));
        // solve the problem and store the result
        int ans = solve(grid, 0, 0, 0, 0, grid.size(), grid[0].size(), dp);

        if(ans < 0)
            return 0;
            
        return ans;
    }
};