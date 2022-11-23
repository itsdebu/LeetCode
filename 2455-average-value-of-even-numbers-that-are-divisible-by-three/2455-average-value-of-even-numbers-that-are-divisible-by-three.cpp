class Solution {
public:
    int averageValue(vector<int>& nums) {
        int c=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0 and nums[i]%3==0)
            {
                sum+=nums[i];
                c++;
            }
        }
        if(c==0)return 0;
        else return sum/c;
    }
};