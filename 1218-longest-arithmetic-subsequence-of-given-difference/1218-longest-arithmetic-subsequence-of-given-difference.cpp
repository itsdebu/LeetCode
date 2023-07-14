class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d)
    {
         int ret = 1;
        unordered_map<int, int> mp = {};
        for(auto &it : arr) ret = max(ret, mp[it] = 1 + mp[it - d]);
        return ret;
    }
};