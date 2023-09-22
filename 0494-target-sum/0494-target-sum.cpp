class Solution {
public:
    
    int count_ways(int index,int target,int sum,vector<int>&nums)
    {
        if(index==nums.size())
        {
            if(sum==target)return 1;
            return 0;
        }
        // if(dp[index][sum]!=-1)return dp[index][sum];
        int plus = count_ways(index+1,sum+ nums[index],target,nums);
        int minus = count_ways(index+1,sum - nums[index],target,nums);

        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // memset(dp,-1,sizeof(dp));
        return count_ways(0,target,0,nums);
    }   
};