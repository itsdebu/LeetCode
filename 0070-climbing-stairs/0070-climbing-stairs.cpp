class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)return 1;
        int s=0,s1=1,ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=s+s1;
            s=s1;
            s1=ans;
        }return ans;
    }
};