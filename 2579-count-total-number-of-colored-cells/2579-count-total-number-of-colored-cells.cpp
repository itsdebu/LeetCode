class Solution {
public:
    long long coloredCells(int n) {
        long long c=1;
        for(long long i=1;i<n;i++)
        {
            c=c+4*i;
        }return c;
    }
};