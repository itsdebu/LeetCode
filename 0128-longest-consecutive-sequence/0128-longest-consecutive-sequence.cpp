class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto it:nums)mp[it]++;

        int max_length = 0;
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            if(mp.find(num-1)==mp.end())
            {
                int count = 1;
                while(mp.find(num+1)!=mp.end())
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