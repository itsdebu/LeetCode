class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        int zero_count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1] and nums[i]!=0){
                ans.push_back(nums[i]*2);
                nums[i+1]=0;
            }
            else if(nums[i]!=nums[i+1] and nums[i]!=0) {
                ans.push_back(nums[i]);
                            }
            if(nums[i]==0)zero_count++;
        }
        if(nums[nums.size()-1]==0)zero_count++;
        else if(nums[nums.size()-1]!=0)ans.push_back(nums[nums.size()-1]);
        while(zero_count--)ans.push_back(0);
        return ans;
    }
};