class Solution {
public:
int dp[501][501];
    int min_steps(int index1,int index2,string &s1,string &s2)
    {

        if(index2<0)return index1+1;
        if(index1<0)return index2+1;

        if(dp[index1][index2]!=-1)return dp[index1][index2];
        
        if(s1[index1]==s2[index2])
        {
            return min_steps(index1-1,index2-1,s1,s2);
        }
        return dp[index1][index2] = min({1 + min_steps(index1-1,index2,s1,s2),1 + min_steps(index1-1,index2-1,s1,s2), 1 +min_steps(index1,index2-1,s1,s2)});

    }
    int minDistance(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return min_steps(s1.size()-1,s2.size()-1,s1,s2);
    }   
};