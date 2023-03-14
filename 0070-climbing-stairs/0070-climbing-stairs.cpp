class Solution {
public:
    int climbStairs(int n) {
        if(n<=3)return n;
        int prev=2;
        int sec_prev=1;
        for(int i=3;i<=n;i++)
        {
            int ans=prev+sec_prev;
            sec_prev=prev;
            prev=ans;
        }return prev;
    }
};