class Solution {
public:
    // step 1, check an element which is lesser than the element which is ahead of it i<i+1 .
    // step 2, check again prom backwards the no which is greater than taht element.
    // steps 3, swap both elements.
    // step 4, reverse the array ahead of that element. 
    void nextPermutation(vector<int>& nums) {
        int index = -1,element = 0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                index = i;
                element = nums[i];
                break;
            }
        }
        if(index==-1)
        {
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=nums.size()-1;i>=0;i--)
            {
                if(nums[i]>element)
                {
                    swap(nums[i],nums[index]);
                    break;
                }
            }
            reverse(nums.begin() + (index + 1), nums.end());
        }
    }
};