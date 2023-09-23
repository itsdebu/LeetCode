class Solution {
public:
    int min_insertion(int index1,int index2,string &s1,string &s2,vector<vector<int>>&dp)
    {
        if(index1<0 or index2<0)
        {
            return 0;            
        }

        if(dp[index1][index2]!=-1)return dp[index1][index2];

        int match = 0,not_match1 = 0,not_match2 = 0;

        if(s1[index1]==s2[index2])
        {
            match = 1 + min_insertion(index1-1,index2-1,s1,s2,dp);
        }
        else {
            not_match1 = min_insertion(index1-1,index2,s1,s2,dp);
            not_match2 = min_insertion(index1,index2-1,s1,s2,dp);
        }

        return dp[index1][index2] = max({match,not_match1,not_match2});
    }
    int minInsertions(string s1) {
        int n = s1.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int ans = min_insertion(s1.size()-1,s1.size()-1,s1,s2,dp);

        return s1.size() - ans;
    }
};