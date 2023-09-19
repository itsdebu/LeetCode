class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int pointer = nums.size()-1;
        vector<int>sorted(nums.size());
        while(i<=j)
        {
            if(abs(nums[i])<abs(nums[j]))
            {
                sorted[pointer--] = nums[j]*nums[j]; 
                j--;
            }
            else 
            {
                sorted[pointer--] = nums[i]*nums[i];
                i++;
            }
        }return sorted;
    }
};