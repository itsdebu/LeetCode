class Solution {
public:
    int dp[1001][1001];
    int find_lcs(int index1,int index2,string &s1,string &s2)
    {
        if(index1<0 or index2<0)return 0;

        int take = 0,not_take1 = 0,not_take2 = 0;

        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(s1[index1] == s2[index2])
        {
            take = 1 + find_lcs(index1-1,index2-1,s1,s2);
        }
        else
        {
            not_take1 = find_lcs(index1-1,index2,s1,s2);
            not_take2 = find_lcs(index1,index2-1,s1,s2);
        }
        return dp[index1][index2] = max({not_take1,take,not_take2});
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return find_lcs(text1.size()-1,text2.size()-1,text1,text2);
    }
};