class Solution {
public:
    int dp[301][301];
    int max_earn(int i,int j,vector<int>&nums)
    {
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mx=INT_MIN;
        for(int ind=i;ind<=j;ind++)
        {
            int cost=(nums[i-1]*nums[ind]*nums[j+1]) + max_earn(i,ind-1,nums) + max_earn(ind+1,j,nums);
            mx=max(mx,cost);
        }return dp[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return max_earn(1,n,nums);
    }
};