class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        if(grid.size()==1)return 1;
        int n=grid.size();
        pair<int,int>source={0,0},destination={n-1,n-1};
        if(source==destination)return 0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        q.push({{0,0},0});
        dist[0][0]=0;
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            if(row==n-1 and col==n-1)return steps+1;
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    int new_row=row+delrow;
                    int new_col=col+delcol;
                    if(new_row>=0 and new_row<n and new_col>=0 and new_col<n and grid[new_row][new_col]==0)
                    {
                        if(dist[row][col]+1<dist[new_row][new_col])
                        {
                            dist[new_row][new_col]=1+dist[row][col];
                            q.push({{new_row,new_col},steps+1});
                        }
                    }
                }
            }
        }return -1;
    }
};