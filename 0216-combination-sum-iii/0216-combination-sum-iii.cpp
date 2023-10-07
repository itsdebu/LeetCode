class Solution {
public:
    void find_sum(int index,int k,int target,vector<int>&nums,vector<int>&path,vector<vector<int>>&res)
    {
        if(target == 0 and k == 0)
        {
            res.push_back(path);
            return;
        }
        if(index == nums.size())
        {
            if(target == 0 and k == 0)
            {
                res.push_back(path);
                return;
            }
            else return;
        }

        if(nums[index]<=target)
        {
            path.push_back(nums[index]);
            find_sum(index+1,k-1,target-nums[index],nums,path,res);
            path.pop_back();
        }
        find_sum(index+1,k,target,nums,path,res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>nums,path;
        for(int i=1;i<=9;i++)nums.push_back(i);
        find_sum(0,k,n,nums,path,res);
        return res;

    }
};