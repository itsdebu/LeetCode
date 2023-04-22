class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&board,int delrow[],int delcol[])
    {
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int new_row=row+delrow[i];
            int new_col=col+delcol[i];
            if(new_row>=0 and new_row<n and new_col>=0 and new_col<m and !vis[new_row][new_col] and board[new_row][new_col]=='O')
            {
                dfs(new_row,new_col,vis,board,delrow,delcol);
            }
        }
    }
public: 
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] and board[i][0]=='O')dfs(i,0,vis,board,delrow,delcol);
            if(!vis[i][m-1] and board[i][m-1]=='O')dfs(i,m-1,vis,board,delrow,delcol);
        }
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] and board[0][j]=='O')dfs(0,j,vis,board,delrow,delcol);
            if(!vis[n-1][j] and board[n-1][j]=='O')dfs(n-1,j,vis,board,delrow,delcol);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0)board[i][j]='X';
            }
        }
        
    }
};