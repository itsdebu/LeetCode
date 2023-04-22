class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>nums,int delrow[],int delcol[])
    {
        int n=nums.size();
        int m=nums[0].size();
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty())
        {
            int new_row=q.front().first;
            int new_col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int next_row=new_row+delrow[i];
                int next_col=new_col+delcol[i];
                if(next_row>=0 and next_row<n and next_col>=0 and next_col<m and !vis[next_row][next_col] and nums[next_row][next_col]=='1')
                {
                    q.push({next_row,next_col});
                    vis[next_row][next_col]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and nums[i][j]=='1')
                {
                    count++;
                    dfs(i,j,vis,nums,delrow,delcol);
                }
            }
        }return count;
    }
};