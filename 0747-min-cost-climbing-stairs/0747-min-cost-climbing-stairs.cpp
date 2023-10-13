class Solution {
public:
    int dp[1001];
    int min_cost(int index,vector<int>&cost)
    {
        if(index>=cost.size())return 0;
        
        if(dp[index]!=-1)return dp[index];
        int take_one_step = cost[index] + min_cost(index+1,cost);
        int take_two_step = cost[index] + min_cost(index+2,cost);

        return dp[index] = min(take_one_step,take_two_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int starting_from_zero = min_cost(0,cost);

        int starting_from_one = min_cost(1,cost);

        return min(starting_from_zero,starting_from_one);
    }
};