class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n= grid.size(), count_pairs=0;
        
        unordered_map<string,int> mp;
        
         //put in the map for each row
        
        for(int i=0;i<n;i++)
        {
            string row="";
            
            for(int j=0;j<n;j++)
            {
                row+= to_string(grid[i][j]) +" ";
            }
            
            mp[row]++;
        }
        
        //collect pairs by storing columns in map
        
        for(int i=0;i<n;i++)
        {
            string column="";
            
            for(int j=0;j<n;j++)
            {
                column+= to_string(grid[j][i]) +" ";
            }
            
            count_pairs+= mp[column];
        }
        return count_pairs;
    }
};