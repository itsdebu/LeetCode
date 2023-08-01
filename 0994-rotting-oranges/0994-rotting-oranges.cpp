class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
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
        int deltarow[4]={-1,0,1,0};
        int deltacol[4]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int new_time=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int new_row=row+deltarow[i];
                int new_col=col+deltacol[i];
                if(new_row>=0 and new_row<n and new_col>=0 and new_col<m and grid[new_row][new_col]==1)
                {
                    grid[new_row][new_col]=2;
                    q.push({{new_row,new_col},new_time+1});
                    time=max(time,new_time+1);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)return -1;
            }
        }
        return time;
    }
};