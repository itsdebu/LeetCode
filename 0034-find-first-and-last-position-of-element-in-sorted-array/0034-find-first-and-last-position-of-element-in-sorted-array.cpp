class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1,last = -1;

        int low = 0,high = nums.size()-1;
        // searching for first occ
        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(nums[mid]==target)
            {
                first = mid;
                high = mid - 1;
            }
            else if(target>nums[mid])
            {
                low = mid+1;
            }
            else high = mid-1;
        }
        // searching for last occ
        low = 0,high = nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(nums[mid]==target)
            {
                last = mid;
                low = mid + 1;
            }
            else if(target>nums[mid])
            {
                low = mid+1;
            }
            else high = mid-1;
        }
        if(first == -1 and last == -1)return {-1,-1};
        else return {first,last};
    }
};