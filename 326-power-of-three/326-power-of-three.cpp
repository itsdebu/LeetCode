class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        int i=0;
        for(i=n;i%3==0;i/=3);
        if(i==1)return 1;
        return 0;
    }
};