class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2)
            return 1;
        else
        {
            int x=coordinates[0][0]-coordinates[1][0];
            int y=coordinates[0][1]-coordinates[1][1];
            for(int i=2;i<coordinates.size();i++)
            {
                if((y*(coordinates[0][0]-coordinates[i][0]))!=(x*(coordinates[0][1]-coordinates[i][1])))
                    return 0;
            }return 1;
        }
        
    }
};