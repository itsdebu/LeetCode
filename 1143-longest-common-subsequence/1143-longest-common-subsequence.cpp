class Solution {
public:
    int dp[1000+1][1000+1];
    int max_common(int index1,int index2,string &str1,string &str2)
    {
        if(index1==0 or index2==0)return 0;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(str1[index1-1]==str2[index2-1])
        {
            return dp[index1][index2]=1+max_common(index1-1,index2-1,str1,str2);
        }
        else
        {
            return dp[index1][index2]=max(0+max_common(index1-1,index2,str1,str2),max_common(0+index1,index2-1,str1,str2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),n1=text2.size();
        memset(dp,-1,sizeof(dp));
        return max_common(n,n1,text1,text2);
    }
};