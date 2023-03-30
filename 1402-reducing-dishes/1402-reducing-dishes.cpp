class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=1;i<nums.size();i++)
        {
            nums[i]=nums[i]+nums[i-1];
        }
        int sum=0,mx=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mx=max(mx,sum);
        }return mx;
    }
};