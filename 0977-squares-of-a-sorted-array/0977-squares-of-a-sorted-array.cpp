class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        int i=0,j=nums.size()-1;
        int pointer=n-1;
        while(i<=j)
        {
            if(abs(nums[i])<abs(nums[j]))
            {
                v[pointer--]=nums[j]*nums[j];
                j--;
            }
            else
            {
                v[pointer--]=nums[i]*nums[i];
                i++;
            }
        }
        return v;
    }
};