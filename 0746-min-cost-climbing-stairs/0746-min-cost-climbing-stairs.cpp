class Solution {
public:
    int dp[1000];
    int min_cost(int index,vector<int>&cost)
    {
        if(index>=cost.size())return 0;
        if(index==cost.size()-1)return cost[index];
        if(dp[index]!=-1) return dp[index];
        
        int one_jump = cost[index] + min_cost(index+1,cost);
        int two_jump = cost[index] + min_cost(index+2,cost);
        return dp[index] = min(one_jump,two_jump);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(min_cost(0,cost),min_cost(1,cost));
    }
};