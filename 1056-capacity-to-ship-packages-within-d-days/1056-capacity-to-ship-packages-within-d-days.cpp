class Solution {
public:
    bool can_ship(vector<int>&nums,int mid,int d)
    {
        int count = 0,runn_sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            runn_sum+=nums[i];
            if(runn_sum>mid)
            {
                runn_sum = nums[i];
                count++;
            }
        }
        if(runn_sum<=mid)count++;
        return count<=d;

    }
    int shipWithinDays(vector<int>& nums, int d) {
        // sort(nums.begin(),nums,end());
        int mx = *max_element(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);

        int low = mx,high = sum;
        int ans = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            bool min_days = can_ship(nums,mid,d);
            if(min_days)
            {
                ans = min(ans,mid);
                high = mid-1;
            }
            else low = mid+1;
        }return ans;
    }
};