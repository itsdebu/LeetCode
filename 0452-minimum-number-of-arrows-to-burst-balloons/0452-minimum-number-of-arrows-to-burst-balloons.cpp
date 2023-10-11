class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int min_ballons = 0;
        sort(points.begin(), points.end(), comp);
        int comp = points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(comp>=points[i][0] and comp<=points[i][1])
            {
                if(i==points.size()-1)min_ballons++;
            }
            else {
                min_ballons++;
                comp = points[i][1];
                if(i == points.size()-1)min_ballons++;
            }
        }
        if(min_ballons == 0 and points.size()>0)return 1;
        return min_ballons;
    }
};