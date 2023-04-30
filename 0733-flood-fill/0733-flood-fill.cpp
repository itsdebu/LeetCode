class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&image,int initial_color,int color,int deltarow[],int deltacol[])
    {
        int n=image.size();
        int m=image[0].size();
        image[r][c]=color;
        for(int i=0;i<4;i++)
        {
            int new_row=r+deltarow[i];
            int new_col=c+deltacol[i];
            if(new_row>=0 and new_row<n and new_col>=0 and new_col<m and image[new_row][new_col]!=color and image[new_row][new_col]==initial_color)
            {
                dfs(new_row,new_col,image,initial_color,color,deltarow,deltacol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int initial_color=image[sr][sc];
        int deltarow[4]={-1,0,1,0};
        int deltacol[4]={0,1,0,-1};
        dfs(sr,sc,image,initial_color,color,deltarow,deltacol);
        return image;
    }
};