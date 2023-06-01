class Solution {
public:
    int dp[501][501];
    int min_operations(string &s1,string &s2,int i,int j)
    {
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])
        {
            return dp[i][j]=min_operations(s1,s2,i-1,j-1);
        }
        return dp[i][j]=min({1+min_operations(s1,s2,i-1,j),1+min_operations(s1,s2,i,j-1),1+min_operations(s1,s2,i-1,j-1)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        memset(dp,-1,sizeof(dp));
        return min_operations(word1,word2,n-1,m-1);
    }
};