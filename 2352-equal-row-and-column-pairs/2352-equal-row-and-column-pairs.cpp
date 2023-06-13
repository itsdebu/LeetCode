class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int total_count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=0;
                for(int col=0;col<n;col++)
                {
                    if(grid[i][col]!=grid[col][j])
                    {
                        count=1;
                    }
                }
                if(count==0)total_count++; 
            }
        }return total_count;
    }
};