class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair< pair<int,int>,int>>> q;
        q.push({{0,0},0});
        dist[0][0]=0;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty())
        {
            int dis=q.top().second;
            int row=q.top().first.first;
            int col=q.top().first.second;
            q.pop();
            if(row==n-1 and col==m-1)return dis;
            for(int i=0;i<4;i++)
            {
                int new_row=row+delrow[i];
                int new_col=col+delcol[i];
                if(new_row>=0 and new_row<n and new_col>=0 and new_col<m and dist[new_row][new_col]>max(abs(heights[row][col]-heights[new_row][new_col]),dis))
                {
                    dist[new_row][new_col]=max(abs(heights[row][col]-heights[new_row][new_col]),dis);
                    q.push({{new_row,new_col},dist[new_row][new_col]});
                }
            }
        }return -1;
    }
};