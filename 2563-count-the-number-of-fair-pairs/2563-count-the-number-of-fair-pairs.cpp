class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());     
        long long sum = 0;
        int j=1,k=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            j = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin(); 
            k = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            if(j <= k)
                sum += k-j;
        }
        return sum;
    }
};