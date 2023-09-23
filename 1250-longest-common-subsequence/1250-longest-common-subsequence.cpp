class Solution {
public:
int dp[1001][1001];
    int match(int index1,int index2,string &s1,string &s2)
    {
        if(index1<0 or index2<0)return 0;

        if(dp[index1][index2]!=-1)return dp[index1][index2];

        int matching = 0,not_match1 = 0,not_match2 = 0;
        if(s1[index1]==s2[index2])
        {
            matching = 1 + match(index1-1,index2-1,s1,s2);
        }
        else {
            not_match1 = match(index1-1,index2,s1,s2);
            not_match2 = match(index1,index2-1,s1,s2);
        }
        return dp[index1][index2] = max({matching,not_match1,not_match2});
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return match(text1.size()-1,text2.size()-1,text1,text2);
    }
};