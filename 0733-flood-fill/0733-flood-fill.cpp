class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
         queue<pair<int,int>>q;
         int n=image.size();
         int m=image[0].size();
         q.push({sr,sc});
         visited[sr][sc]=true;
        //  return visited;
        int che=image[sr][sc];
        int alpha[4]={0,0,1,-1};
        int beta[4]={1,-1,0,0};
        while(!q.empty()){
            pair<int,int>fr=q.front();
            q.pop();
            for(int i=0;i<4;i++){

                int x=fr.first+alpha[i];
                int y=fr.second+beta[i];
                if(x<n && y<m && x>=0 && y>=0 && visited[x][y]==false){
                    if(image[x][y]==che){
                        q.push({x,y});
                        visited[x][y]=true;
                        cout<<x<<" "<<y<<endl;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==1){
                    image[i][j]=color;
                }
            }
        }

        return image;

    }
};