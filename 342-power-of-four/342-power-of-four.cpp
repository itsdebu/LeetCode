class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        int i=0;
        for(i=n;i%4==0;i/=4);
        if(i==1)return 1;
        return 0;
    }
};