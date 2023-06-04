class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        int prev_one=1,prev_two=0;
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            ans=prev_one+prev_two;
            prev_two=prev_one;
            prev_one=ans;
        }return prev_one;
    }
};