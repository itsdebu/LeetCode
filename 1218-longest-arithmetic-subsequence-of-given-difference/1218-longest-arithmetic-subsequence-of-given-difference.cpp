class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d)
    {
         int ans = 1;
        unordered_map<int, int> mp = {};
        for(int i=0;i<arr.size();i++)
        {
            ans=max(ans,mp[arr[i]]=mp[arr[i]-d]+1);
        }
        return ans;
    }
};