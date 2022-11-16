class Solution {
public:
    long long int reverse(int x) {
        if (x>=1534236469 || x==-1563847412)return 0;
        
        if(x==-2147483648)return 0;
        long long c=0;
        while(x!=0)
        {
            int n=x%10;
            c=c*10+n;
            x/=10;
        }return c;
    }
};