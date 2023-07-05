class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=INT_MIN;
        int cnt = count(nums.begin(),nums.end(),1);
        int zero_count = count(nums.begin(),nums.end(),0);
        if(cnt==nums.size())return cnt-1;
        if(zero_count==nums.size())return 0;
        zero_count=0,cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                zero_count=0;
                int index=-1,j=i;
                while(j!=nums.size())
                {
                    if(nums[j]==1)cnt++;
                    else
                    {
                        if(zero_count==0)
                        {
                            zero_count++;
                            index=j;
                        }
                        else
                            break;
                    }
                    j++;
                }
                mx=max(mx,cnt);
                cnt=0;
                if(index!=-1)i=index;
                if(j==nums.size()-1)break;
            }
        }
        return max(mx,cnt);
    }
};