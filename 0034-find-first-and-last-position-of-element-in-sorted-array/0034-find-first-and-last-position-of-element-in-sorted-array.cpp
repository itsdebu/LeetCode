class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int c=-1,c1=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(t==nums[i])
            {
                c=i;
                break;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(t==nums[i])
            {
                c1=i;
            }
        }
        return {c,c1};
    }
};