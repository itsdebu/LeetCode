class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc = 0,dec = 0;
        if(nums.size()==1)return 1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                inc = 1;
                break;
            }
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i]){
                dec = 1;
                // cout<<1<<endl;
                break;
            }
        }
        if(inc == 1)
        {
            for(int i=0;i<nums.size()-1;i++)
            {
                if(nums[i]<=nums[i+1])
                {
                    continue;
                }
                else return false;
            }
            return true;
        }
        if(dec==1)
        {
            for(int i=1;i<nums.size();i++)
            {
                if(nums[i-1]>=nums[i])continue;
               else{
                //    cout<<i;
                   return false;
               }
            }return true;
        }
        return 1;
    }
};