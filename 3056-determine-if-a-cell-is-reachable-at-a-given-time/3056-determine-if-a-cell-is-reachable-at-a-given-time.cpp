class Solution {
public:
    // bool Reach(int row,int col,int ds,int de,int t)
    // {
    //     if(row<0)
    //     if(t==0 and row==ds and col==de)return 1;
    //     if(t==0)return 0;
    // }
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx and sy==fy and t==0)return 1;
        if(sx==fx and sy==fy and t<=1)return 0;
        int mx = max(abs(fx-sx),abs(fy-sy));
        if(mx<=t)return 1;
        return 0;
    }
};