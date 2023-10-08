class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int max_length = 0;

        int start = 0,end = 0;

        while(end<s.size())
        {
            mp[s[end]]++;

            if(mp[s[end]]>1)
            {
                while(mp[s[end]]>1)
                {
                    mp[s[start]]--;
                    // if(mp[s[start]]==0)mp.erase(s[start]);
                    start++;
                }
            }
            else
            {
                max_length = max(max_length,end-start+1);
            }
            end++;
        }
        return max_length;
    }
};