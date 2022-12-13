class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return 0;;
        int c=0;
        while(n!=0)
        {
            int r=n&-n;
            n-=r;
            c++;
        }if(c==1)return 1;
        else return 0;
    }
};