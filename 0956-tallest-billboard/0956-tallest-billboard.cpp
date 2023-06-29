class Solution {
public:
    vector<unordered_map<int,int>>dp;
    int tallest_sum(int index,vector<int>&rods,int target)
    {
        if(index==rods.size())
        {
            if(target==0)return 0;
            return INT_MIN;
        }
        if(dp[index].find(target)!=dp[index].end())return dp[index][target];
        int not_take = tallest_sum(index+1,rods,target);
        int take = rods[index] + tallest_sum(index+1,rods,target+rods[index]);
        int take_one = tallest_sum(index+1,rods,target-rods[index]);
        return dp[index][target] = max({not_take,take,take_one});
    }
    int tallestBillboard(vector<int>& rods) {
        dp.assign(21,{});
        return tallest_sum(0,rods,0);
    }
};