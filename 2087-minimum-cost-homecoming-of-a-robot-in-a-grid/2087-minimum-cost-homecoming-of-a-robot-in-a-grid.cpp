class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rc, vector<int>& cc) {
        int ans=0;
        if(homePos[0]>=startPos[0])
            for(int i=startPos[0]+1;i<=homePos[0];i++)
            ans+=rc[i];
        else
            for(int i=startPos[0]-1;i>=homePos[0];i--)
            ans+=rc[i];
        if(homePos[1]>=startPos[1])
          for(int i=startPos[1]+1;i<=homePos[1];i++)
            ans+=cc[i];
        else
           for(int i=startPos[1]-1;i>=homePos[1];i--)
            ans+=cc[i];
        return ans;  
    }
};