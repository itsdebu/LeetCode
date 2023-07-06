class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        // vector<int>sum(n+1,0);
        // for(int i=0;i<nums.size();i++)
        // {
        //     sum[i+1]=sum[i]+nums[i];
        // }
        int i=0,j=0;
        int mn=INT_MAX;
        int sum=0,flag=0;
        while(j!=nums.size())
        {
            if(flag==0)sum+=nums[j];
            if(sum>=target)
            {
                mn=min(mn,j-i+1);
                sum-=nums[i];
                i++;
                flag=1;
            }
            else 
            {
                flag=0;
                j++;
            }
        }
        if(mn==INT_MAX)return 0;
        return mn;
    }
};