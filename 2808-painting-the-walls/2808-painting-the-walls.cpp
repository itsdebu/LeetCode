class Solution {
public:
    int dp[501][501];
    int min_cost(int index,vector<int>&cost,vector<int>&time,int wall_rem)
    {
        if(wall_rem<=0)return 0;
        if(index == cost.size())return 1e9;

        if(dp[index][wall_rem]!=-1)return dp[index][wall_rem];

        int take = cost[index] + min_cost(index+1,cost,time,wall_rem-time[index]-1);
        
        int not_take = min_cost(index+1,cost,time,wall_rem);

        return dp[index][wall_rem] = min(take,not_take);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof(dp));
        return min_cost(0,cost,time,cost.size());
    }
};