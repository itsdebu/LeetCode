class Solution {
public:
   int solve(vector<int>& nums,int prevIdx,int idx,vector<vector<int>>& dp){
    if(idx>=nums.size()){
        return dp[prevIdx+1][idx] = 0;
    }
    if(dp[prevIdx+1][idx]!=-1) return dp[prevIdx+1][idx];
    if(prevIdx==-1 || nums[idx]%nums[prevIdx]==0){
        return dp[prevIdx+1][idx] = max(1+solve(nums,idx,idx+1,dp),solve(nums,prevIdx,idx+1,dp));
    }
    return dp[prevIdx+1][idx] = solve(nums,prevIdx,idx+1,dp);
}

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    sort(nums.begin(),nums.end());
    solve(nums,-1,0,dp);
    vector<int> ans;
    int i = 0;    //prevIdx+1--->i
    int j = 0;    //idx--->j
    while(i<n && j<n){
        if(i-1==-1 || nums[j]%nums[i-1]==0){
            if(1+dp[j+1][j+1]>dp[i][j+1]){
                ans.push_back(nums[j]);
                i = j+1;
                j = j+1;
            }
            else{
                j = j+1;
            }
        }
        else{
            j = j+1;
        }
    }
    return ans;
}
};