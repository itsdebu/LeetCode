class Solution {
public:
    int dp[301][301];
    int max_earn(int i,int j,vector<int>&nums)
    {
        if(i>j)return 0;        

        if(dp[i][j]!=-1)return dp[i][j];

        int mx_coins = INT_MIN;

        for(int k = i;k<=j;k++)
        {
            int ans = nums[k] * nums[i-1] * nums[j+1] + max_earn(i,k-1,nums) + max_earn(k+1,j,nums);
            mx_coins = max(mx_coins,ans);
        }
        return dp[i][j] = mx_coins;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        return max_earn(1,n,nums);
    }
};