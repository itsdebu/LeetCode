class Solution {
public:
    int fib(int n) {
        int prev=1;
        int sec_prev=0;
        if(n<=1)return n;
        for(int i=2;i<=n;i++)
        {
            int ans=prev+sec_prev;
            sec_prev=prev;
            prev=ans;
        }return prev;
    }    
};