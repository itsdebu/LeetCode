class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int size = points.size()-k;
        int i=0,j=0;
        int total_sum = accumulate(points.begin(),points.end(),0);
        int mx_points = 0;
        int sum = 0;
        if(k==points.size())return total_sum;
        while(j<points.size())
        {
            sum+=points[j];
            
            if(j-i+1==size)
            {
                mx_points = max(mx_points,total_sum-sum);
                sum-=points[i];
                i++,j++;
            }
            else j++;
        }return mx_points;
    }
};