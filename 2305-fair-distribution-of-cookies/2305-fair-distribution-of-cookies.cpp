class Solution {
public:
    int ans=INT_MAX;
    void fair_sum(vector<int>&sum,int index,vector<int>&nums,int k)
    {
        if(index==nums.size())
        {
            int mx=0;
            for(int i=0;i<k;i++)
            {
                mx=max(mx,sum[i]);
            }
            ans =min(ans,mx);
            return;
        }
        for(int i=0;i<k;i++)
        {
            sum[i]+=nums[index];
            fair_sum(sum,index+1,nums,k);
            sum[i]-=nums[index];
            // if(sum[i]==0)break;
        }
    }
    int distributeCookies(vector<int>& nums, int k) {
        vector<int>sum(k,0);
        fair_sum(sum,0,nums,k);
        return ans;
    }
};