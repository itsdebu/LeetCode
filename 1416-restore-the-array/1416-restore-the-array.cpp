class Solution {
public:
    int dp[100001];
    int mod=1000000007;
    int solve(int index,string &s,int k){
        if(index==s.size()) return 1;
        if(dp[index] != -1)return dp[index];
        else
        {
            if(s[index] == '0') return 0;
            long long num = 0;
            int ans = 0;
            for(int j=index;j<s.size();j++){
                num = num*10+s[j]-'0';
                if(num>k)break;
                ans+=solve(j+1,s,k);
                ans%=mod;
            }
            return dp[index] = ans;
        }
    }
    int numberOfArrays(string s, int k) {
        for(int i=0;i<=s.size(); i++)
            dp[i]=-1;
        return solve(0,s,k);
    }
    
};