class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)count++;
            if(nums[i]!=0 and count>0)
            {
                ans+=(count*(count+1))/2;
                count=0;
            }
        }if(count>0)
        {
            ans+=(count*(count+1))/2;
        }
        return ans;
    }
};