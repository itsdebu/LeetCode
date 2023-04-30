class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            mat[row][col]=steps;
            for(int i=0;i<4;i++)
            {
                int new_row=row+delrow[i];
                int new_col=col+delcol[i];
                if(new_row>=0 and new_row<n and new_col>=0 and new_col<m and vis[new_row][new_col]==0)
                {
                    q.push({{new_row,new_col},steps+1});
                    vis[new_row][new_col]=1;
                }
            }
        }return mat;
    }
};