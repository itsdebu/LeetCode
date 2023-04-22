class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>&nums,int m,int n)
    {
        if(row<0 or row>=n or col<0 or col>=m or nums[row][col]=='0')return;
        nums[row][col]='0';
        dfs(row+1,col,nums,m,n);
        dfs(row,col+1,nums,m,n);
        dfs(row-1,col,nums,m,n);
        dfs(row,col-1,nums,m,n);
        return;
    }
    int numIslands(vector<vector<char>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(nums[i][j]=='1')
                {
                    count++;
                    dfs(i,j,nums,m,n);
                }
            }
        }return count;
    }
};