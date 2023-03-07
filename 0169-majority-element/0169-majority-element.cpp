class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr_element=nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==curr_element)count++;
            else
            {
                count--;
                if(count==0){curr_element=nums[i+1];}
            }
        }return curr_element;
    }
};