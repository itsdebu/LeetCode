class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>v;
        int n = nums.size()/3;
        if(nums.size()==1)return nums;
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=nums.size()-1 and nums[i]==nums[i+1])
            {
                count++;
            }
            else{
                count++;
                if(count>n)v.push_back(nums[i]);
                count=0;}
        }
        // if()
        return v;
    }
};