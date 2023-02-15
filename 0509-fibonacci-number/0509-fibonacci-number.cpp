class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        int s=0,s1=1,ans=0;
        for(int i=2;i<=n;i++)
        {
            ans=s+s1;
            s=s1;
            s1=ans;
        }return ans;
    }
};