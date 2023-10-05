class Solution {
public:
    int findMin(vector<int>& nums) {
         int first=0;
        int n=nums.size();
        int last = n-1;
        int middle=0,prev=0,next=0;
        while (first<=last)
        {
            if (nums[first]<=nums[last])
            {
                return nums[first];
            }
            middle= first + (last-first)/2;
            prev = ( middle - 1 + n ) % n;
            next = ( middle +1 ) % n;
            
            if (nums[middle] <= nums[next] && nums[middle] <= nums[prev])
            {
                return nums[middle];
            }
            if (nums[first] <= nums[middle])
            {
                first = middle + 1;
            }
            if (nums[middle] <= nums[last])
            {
                last= middle-1;
            }
        }
        return -1 ; 
    }
};