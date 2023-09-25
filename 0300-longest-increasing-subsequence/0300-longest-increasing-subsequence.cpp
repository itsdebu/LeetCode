class Solution {
public:
    int dp[2501][2502];
    int find_longest(int index,int prev,vector<int>&nums)
    {
        if(index==nums.size())return 0;

        if(dp[index][prev+1]!=-1)return dp[index][prev+1];

        int take = 0;
        if(prev==-1 || nums[prev]<nums[index])
        {
            take = 1 + find_longest(index+1,index,nums);
        }
        int not_take  = find_longest(index+1,prev,nums);

        return dp[index][prev+1] = max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find_longest(0,-1,nums);
    }
};