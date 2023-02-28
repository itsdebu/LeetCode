class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto i:s)mp[i]++;
        int sum=0;
        for(auto i:mp)
        {
            if(i.second%2!=0)sum++;
        }
        if(sum>1)return s.size()-sum+1;
        return s.size();
    }
};