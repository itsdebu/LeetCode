class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size())return -1;
        int starting=0,ending=0;
        while(starting<=haystack.size() and ending<=needle.size())
        {
            if(haystack[starting]==needle[ending])
            {
                starting++;
                ending++;
                if(ending==needle.size())return starting-ending;
            }
            else 
            {
                starting =starting - ending + 1;
                ending=0;
            }
        }return -1;
    }
};