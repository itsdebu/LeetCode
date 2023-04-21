class Solution {
public:
    int Pivot(vector<int>& nums) {

        int low = 0;
        int high = nums.size()-1;
        int mid=(high+low)/2;

        while(low<high) {

            if(nums[mid] >= nums[0])
            {
                low = mid+1;
            }
            else{
                high = mid;
            }
            mid = (high+low)/2;
        }
        return low;
    }
    int search(vector<int>nums,int target,int low,int high)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)return mid;
            else if(target>nums[mid])low=mid+1;
            else high=mid-1;
        }
        return -1;   
    }
    int search(vector<int>& nums, int target) {
        int pivot = Pivot(nums);
        if(target >= nums[pivot] && target<=nums[nums.size()-1]){
            return search(nums,target,pivot,nums.size()-1);
        }
        else{
            return search(nums,target,0,pivot-1);
        }
    }
};