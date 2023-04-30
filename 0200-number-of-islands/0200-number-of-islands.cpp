class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>grid,int deltarow[],int deltacol[])
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int new_row=r+deltarow[i];
                int new_col=c+deltacol[i];
                if(new_row>=0 and new_row<n and new_col>=0 and new_col<m and !vis[new_row][new_col] and grid[new_row][new_col]=='1')
                {
                    q.push({new_row,new_col});
                    vis[new_row][new_col]=1;
                }   
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int deltarow[4]={-1,0,1,0};
        int deltacol[4]={0,1,0,-1};
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,vis,grid,deltarow,deltacol);
                }
            }
        }return count;
    }
};