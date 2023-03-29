class Solution {
public:
 int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());     // sort no matter the place of elements
        reverse(sat.begin(), sat.end()); // make it to non increasing 
        int n=sat.size();
        vector<int>sum;
        sum = sat;                      // we need a vector for storing prefix sum
        for(int i=1;i<n;i++){
            sum[i]+=sum[i-1];              // storing prefix sum in sum array
        }
        int mx=0,cs=0;              // intislise maximum possible sum and current possible sum
        for(int i=0;i<n;i++){
            cs+=sum[i];             // storing in current sum 
            mx=max(cs,mx);             // comparing 
        }
        return mx;
    }
};