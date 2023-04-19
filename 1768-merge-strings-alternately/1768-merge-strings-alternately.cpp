class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int j=0;
        if(word1.size()>=word2.size())
        {
            for(int i=0;i<word1.size();i++)
            {
                if(j!=word2.size())
                {
                    ans+=word1[i];
                    ans+=word2[i];
                    j++;
                }
                else ans+=word1[i];
            }
        }
        else
        {
            for(int i=0;i<word2.size();i++)
            {
                if(j!=word1.size())
                {
                    ans+=word1[i];
                    ans+=word2[i];
                    j++;
                }
                else ans+=word2[i];
            }
        }return ans;
    }
};