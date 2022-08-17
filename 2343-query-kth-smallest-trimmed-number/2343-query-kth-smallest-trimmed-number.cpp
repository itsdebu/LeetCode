class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
      vector<int>v;
         vector<string> copy;
         int len = nums[0].length();
        for(int i=0;i<q.size();i++)
        {
            copy = nums;
            int target = q[i][0];
            int trim = q[i][1];
           
            int len2 = len-trim;
            for(int j=0;j<nums.size();j++)
            {
               
                    copy[j].erase(0,len2);
                
            }
            vector<pair<string,int>>small;
            for(int y=0;y<copy.size();y++)
            {
                small.push_back({copy[y] , y});
            }
            
            sort(small.begin(),small.end());
            v.push_back(small[target-1].second);
             
        }
        
        return v;
    }
};