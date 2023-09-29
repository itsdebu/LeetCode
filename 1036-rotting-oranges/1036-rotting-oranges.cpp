class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
            }
        }

        int min_time = 0;
        
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            
            q.pop();

            for(int i=0;i<4;i++)
            {
                int new_row = r + delrow[i];
                int new_col = c + delcol[i];

                if(new_row>=0 and new_row<n and new_col>=0 and new_col<m and grid[new_row][new_col]==1 and !vis[new_row][new_col])
                {
                    grid[new_row][new_col] = 2;
                    vis[new_row][new_col] = 1;
                    q.push({{new_row,new_col},time+1});
                }
            }
            min_time = max(min_time,time);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)return -1;
            }
        }
        return min_time;
    }
};