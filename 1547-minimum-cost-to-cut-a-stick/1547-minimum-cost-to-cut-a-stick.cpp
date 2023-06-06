class Solution {
public:
    int min_cost(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mn=INT_MAX;
        for(int ind=i;ind<=j;ind++)
        {
            int cost= cuts[j+1]-cuts[i-1]+min_cost(i,ind-1,cuts,dp)+min_cost(ind+1,j,cuts,dp);
            mn=min(mn,cost);
        }return dp[i][j]= mn;
    }
    int minCost(int n, vector<int>& cuts) {
        int size= cuts.size();
        vector<vector<int>>dp(size+1,vector<int>(size+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return min_cost(1,size,cuts,dp);
    }
};