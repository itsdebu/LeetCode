class Solution {
public:
    void solve(vector<int>nums,vector<int>ans,vector<vector<int>>&res,int i)
    {
        if(i>=nums.size())
        {
            res.push_back(ans);
            return;
        }
        solve(nums,ans,res,i+1);
        ans.push_back(nums[i]);
        solve(nums,ans,res,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ans;
        int i=0;
        solve(nums,ans,res,i);
        return res;
    }
};