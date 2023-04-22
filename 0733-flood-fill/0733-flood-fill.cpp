class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&image,int initial_color,int color,int delrow[],int delcol[])
    {
        int n=image.size();
        int m=image[0].size();
        image[i][j]=color;
        for(int k=0;k<4;k++)
        {
            int row=i+delrow[k];
            int col=j+delcol[k];
            if(row>=0 and row<n and col>=0 and j<m and image[row][col]==initial_color and image[row][col]!=color)
            {
                dfs(row,col,image,initial_color,color,delrow,delcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int initial_color=image[sr][sc];
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        dfs(sr,sc,image,initial_color,color,delrow,delcol);
        return image;
    }
};