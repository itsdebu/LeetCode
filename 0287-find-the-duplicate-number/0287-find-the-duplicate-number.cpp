class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n,0);
        for(int i=0;i<nums.size();i++)freq[nums[i]]++;
        for(int i=0;freq.size();i++)
        {
            if(freq[i]>1)return i;
        }return 0;
    }
};