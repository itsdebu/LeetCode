class Solution {
public:
    int trap(vector<int>& nums) {
        vector<int>max_left(nums.size(),0);
        vector<int>max_right(nums.size(),0);

        max_left[0] = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            max_left[i] = max(max_left[i-1],nums[i]);
        }

        max_right[nums.size()-1] = nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--)
        {
            max_right[i] = max(max_right[i+1],nums[i]);
        }

        int max_trap = 0;

        for(int i=0;i<nums.size();i++)
        {
            max_trap += min(max_left[i],max_right[i]) - nums[i];
        }
        return max_trap;
    }
};