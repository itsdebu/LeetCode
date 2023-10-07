class Solution {
public:

    void CombinationSum(int index,int target,vector<int>&nums,vector<int>&path,set<vector<int>>&res)
    {
        if(target == 0)
        {
            res.insert(path);
            return;
        }
        else if(index == nums.size())
        {
            if(target == 0)
            {
                res.insert(path);
                return;
            }
            else return;
        }
        
        // int take = 0,not_take = 0;
        if(nums[index]<=target)
        {
            path.push_back(nums[index]);
            CombinationSum(index+1,target-nums[index],nums,path,res);
            CombinationSum(index,target-nums[index],nums,path,res);
            path.pop_back();
        }
        CombinationSum(index+1,target,nums,path,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>path;
        set<vector<int>>res;
        CombinationSum(0,target,candidates,path,res);
        for(auto it:res)
        {
            ans.push_back(it);
        }
        return ans;
    }
};