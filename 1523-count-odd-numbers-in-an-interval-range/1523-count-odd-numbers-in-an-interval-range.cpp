class Solution {
public:
    int countOdds(int l, int h) {
        if((h-l+1)%2==0)return (h-l+1)/2;
        else
        {
            if(h%2==0 && l%2==0)
            {
                return (h-l+1)/2;
            }
            else if(h%2!=0 && l%2!=0)
            {
                return (h-l+1)/2+1;                          
            }
            else return (h-l+1)/2+1;
        }
    }
};