class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return 0;
        if(x==0)return 1;
        long long num=0,num1=x;
        while(x!=0)
        {
            int k=x%10;
            num=num*10+k;
            x/=10;
        }cout<<num;
        if(num==num1)return 1;
        return 0;
    }
};