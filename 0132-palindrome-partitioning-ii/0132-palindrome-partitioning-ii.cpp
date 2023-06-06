class Solution {
public:
    bool isPalindrome(int i,int j,string &s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])return false;
            i++,j--;
        }return true;
    }
    int min_cut(int i,int n,string &s,vector<int>&dp)
    {
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int mn=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(isPalindrome(i,j,s))
            {
                int cost= 1+min_cut(j+1,n,s,dp);
                mn=min(mn,cost);
            }
        }return dp[i]=mn;
    }
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return min_cut(0,s.size(),s,dp)-1;
    }
};