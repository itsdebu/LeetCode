class Solution {
public:
    int dp[301][5001];
    int count_ways(int index,int target,vector<int>&coins)
    {
        if(target==0)return 1;
        if(index==coins.size()-1)
        {
            if(target%coins[index]==0)return 1;
            return 0;
        }
        if(dp[index][target]!=-1)return dp[index][target];

        int take = 0,not_take = 0;

        if(target>=coins[index])
        {
            take = count_ways(index,target-coins[index],coins);
        }
        not_take = count_ways(index+1,target,coins);

        return dp[index][target] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return count_ways(0,amount,coins);
    }
};