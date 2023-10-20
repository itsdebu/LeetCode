class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto it:nums)mp[it]++;

        int max_length = 0;
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            if(mp[num-1]==0)
            {
                int count = 1;
                while(mp[num+1]>0)
                {
                    count++;
                    num += 1;
                }
                max_length = max(max_length , count);
            }
        }
        return max_length;
    }
};