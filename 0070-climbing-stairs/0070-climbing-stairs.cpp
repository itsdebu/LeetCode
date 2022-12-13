class Solution {
public:
    int climbStairs(int n) {
        int prev=0,curr=1;
        if(n==1)return 1;
        for(int i=1;i<n;i++)
        {
            prev=curr-prev;
            curr=curr+prev;
        }return curr;
    }
};