class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        if(n==3)return 0;
        sort(nums.begin(),nums.end());
        int c=nums[n-2]-nums[1];
        int c1=nums[n-3]-nums[0];
        int c2=nums[n-1]-nums[2];
        return min(c,min(c1,c2));
        
    }
};