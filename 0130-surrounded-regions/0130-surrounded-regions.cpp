class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&mat,int deltarow[],int deltacol[])
    {
        int n=mat.size();
        int m=mat[0].size();
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=row+deltarow[i];
            int ncol=col+deltacol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and mat[nrow][ncol]=='O' and !vis[nrow][ncol])
            {
                dfs(nrow,ncol,vis,mat,deltarow,deltacol);
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int deltarow[4]={-1,0,1,0};
        int deltacol[4]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] and mat[i][0]=='O')dfs(i,0,vis,mat,deltarow,deltacol);
            if(!vis[i][m-1] and mat[i][m-1]=='O')dfs(i,m-1,vis,mat,deltarow,deltacol);
        }
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] and mat[0][j]=='O')dfs(0,j,vis,mat,deltarow,deltacol);
            if(!vis[n-1][j] and mat[n-1][j]=='O')dfs(n-1,j,vis,mat,deltarow,deltacol);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and mat[i][j]=='O')
                {
                    mat[i][j]='X';
                }
            }
        }
    }
};