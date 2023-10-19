class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx_sum = nums[0];
        int curr_sum = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            curr_sum += nums[i];

            if(curr_sum<nums[i])curr_sum = nums[i];

            mx_sum = max(mx_sum , curr_sum);
        }return mx_sum;
    }
};