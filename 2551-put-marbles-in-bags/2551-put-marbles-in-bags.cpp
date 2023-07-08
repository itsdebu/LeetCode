class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        if(k==1 or k==nums.size())return 0;
        vector<long long>sum;
        k--;
        for(int i=1;i<nums.size();i++)
        {
            sum.push_back(nums[i]+nums[i-1]);
        }
        sort(sum.begin(),sum.end());
        long long st=0,ls=0;
        int temp=k;
        for(int i=0;i<sum.size();i++)
        {
            if(k==0)break;
            st+=sum[i];
            k--;
        }
        for(int i=sum.size()-1;i>=0;i--)
        {
            if(temp==0)break;
            ls+=sum[i];
            temp--;
        }
        return ls-st;
    }
};