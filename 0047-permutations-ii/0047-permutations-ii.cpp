class Solution {
public:
    void unique_permutation(int index,vector<int>&nums,set<vector<int>>&st)
    {
        if(index == nums.size())
        {
            st.insert(nums);
            return;
        }

        for(int i = index ; i < nums.size() ; i++ )
        {
            swap(nums[index],nums[i]);
            unique_permutation(index+1,nums,st);
            swap(nums[index],nums[i]);

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        unique_permutation(0,nums,st);
        vector<vector<int>>ans;
        for(auto it:st)ans.push_back(it);
        return ans;

    }
};